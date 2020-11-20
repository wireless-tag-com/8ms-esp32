/* HTTP GET Example using plain POSIX sockets

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "blockly_http.h"
#include "esp_log.h"
#include "../wifi/blockly_wifi.h"
#include "../data_analysis/blockly_data_analysis.h"


static const char *TAG = "blockly_http";

static const char *REQUEST = "GET %s HTTP/1.0\r\n"
    "Host: %s\r\n"
    "\r\n";
//const char *json_str =
//   "{\"code\":20000,\"message\":\"正常响应\",\"data\":{\"subTopic\":\"/30AEA4C9335C/user/deviceMsg\",\"password\":\"secret\",\"port\":1883,\"host\":\"132.232.54.102\",\"pubTopic\":\"/30AEA4C9335C/user/cloudPlatformMsg\",\"userName\":\"admin\"},\"subTopic\":\"/30AEA4C9335C/user/deviceMsg\"}";


/*http 请求标志位：1：请求；0：无请求；*/
static int http_request_flag = 0;
/*htttp 积木块开启标志位 true：开启；false：关闭*/
static bool blockly_http_flag = false;

static blockly_http_msg_t g_b_http_msg;

__attribute__((weak)) void http_callback(char* data)
{
    ;
}

static int http_get_handle(char *server, char *port, char *url)
{
    const struct addrinfo hints = {
        .ai_family = AF_INET,
        .ai_socktype = SOCK_STREAM,
    };
    struct addrinfo *res;
    struct in_addr *addr;
    int s, r;
    char recv_buf[64];
    char requst[1024] = {0};
    sprintf(requst,REQUEST,url,server);

    int user_buff_len = 0;
    char user_buff[32];
    memset(user_buff,0,sizeof(user_buff));

    //while(1) {
        int err = getaddrinfo(server,port, &hints, &res);

        if(err != 0 || res == NULL) {
            ESP_LOGE(TAG, "DNS lookup failed err=%d res=%p", err, res);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            return err;
        }

        /* Code to print the resolved IP.

           Note: inet_ntoa is non-reentrant, look at ipaddr_ntoa_r for "real" code */
        addr = &((struct sockaddr_in *)res->ai_addr)->sin_addr;
        ESP_LOGI(TAG, "DNS lookup succeeded. IP=%s", inet_ntoa(*addr));

        s = socket(res->ai_family, res->ai_socktype, 0);
        if(s < 0) {
            ESP_LOGE(TAG, "... Failed to allocate socket.");
            freeaddrinfo(res);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            return err;
        }
        ESP_LOGI(TAG, "... allocated socket");

        if(connect(s, res->ai_addr, res->ai_addrlen) != 0) {
            ESP_LOGE(TAG, "... socket connect failed errno=%d", errno);
            close(s);
            freeaddrinfo(res);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            return err;
        }

        ESP_LOGI(TAG, "... connected");
        freeaddrinfo(res);

        if (write(s, requst, strlen(requst)) < 0) {
            ESP_LOGE(TAG, "... socket send failed");
            close(s);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            return err;
        }
        ESP_LOGI(TAG, "... socket send success");

        struct timeval receiving_timeout;
        receiving_timeout.tv_sec = 5;
        receiving_timeout.tv_usec = 0;
        if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &receiving_timeout,
                sizeof(receiving_timeout)) < 0) {
            ESP_LOGE(TAG, "... failed to set socket receiving timeout");
            close(s);
            vTaskDelay(4000 / portTICK_PERIOD_MS);
            return err;
        }
        ESP_LOGI(TAG, "... set socket receiving timeout success");

        /* Read HTTP response */
        printf("\n");
        memset(requst,0,sizeof(requst));
        do {
            bzero(recv_buf, sizeof(recv_buf));
            r = read(s, recv_buf, sizeof(recv_buf)-1);
            for(int i = 0; i < r; i++) {
                putchar(recv_buf[i]);
                requst[user_buff_len] = recv_buf[i];
                user_buff_len++;
            }
        } while(r > 0);
        printf("\n");
        //////////////////json 处理//////////////////
        char *json_data = (char *)strstr(requst,"\r\n\r\n");
        json_data += 4;
        http_callback(json_data);
        json_data = NULL;
        ///////////////////////////////////////////////

        ESP_LOGI(TAG, "... done reading from socket. Last read return=%d errno=%d.", r, errno);
        close(s);
        /*
        for(int countdown = 10; countdown >= 0; countdown--) {
            ESP_LOGI(TAG, "%d... ", countdown);
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        */
        ESP_LOGI(TAG, "http request end!");
    //}
    return 0;
}

void user_set_http_msg(char *server,char *port,char *url)
{
    g_b_http_msg.h_server_len = strlen(server);
    g_b_http_msg.h_port_len = strlen(port);
    g_b_http_msg.h_url_len = strlen(url);
    memcpy(g_b_http_msg.h_server,server,g_b_http_msg.h_server_len);
    memcpy(g_b_http_msg.h_port,port,g_b_http_msg.h_port_len);
    memcpy(g_b_http_msg.h_url,url,g_b_http_msg.h_url_len);
    ESP_LOGI(TAG, "4 = [%s]-[%s]-[%s]\n",g_b_http_msg.h_server,g_b_http_msg.h_port,g_b_http_msg.h_url);
    http_request_flag = 1;
    blockly_http_loop();
}

void blockly_http_init()
{
    blockly_http_flag = true;
    
    g_b_http_msg.h_server_len = 0;
    g_b_http_msg.h_port_len = 0;
    g_b_http_msg.h_url_len = 0;
    g_b_http_msg.h_server = (char *)malloc(128);
    g_b_http_msg.h_port = (char *)malloc(32);
    g_b_http_msg.h_url = (char *)malloc(128);
    memset(g_b_http_msg.h_server,0,128);
    memset(g_b_http_msg.h_port,0,32);
    memset(g_b_http_msg.h_url,0,128);
}


void blockly_http_loop()
{
    if(blockly_http_flag == false){
        return;
    }
    if(gl_sta_connected == false){
        return;
    }
    if(0 == http_request_flag){
        return;
    }
    http_get_handle(g_b_http_msg.h_server,g_b_http_msg.h_port,g_b_http_msg.h_url);
    
    g_b_http_msg.h_server_len = 0;
    g_b_http_msg.h_port_len = 0;
    g_b_http_msg.h_url_len = 0;
    memset(g_b_http_msg.h_server,0,128);
    memset(g_b_http_msg.h_port,0,32);
    memset(g_b_http_msg.h_url,0,128);

    http_request_flag = 0;
}
