#pragma once

#ifdef __cplusplus
extern "C" {
#endif

int gt1151_pos_read(uint16_t *xpos, uint16_t *ypos);
esp_err_t gt1151_i2c_init(int bus_num, uint32_t clk_speed, int scl, int sda);

int gt1151_init(int32_t x, int32_t y);

#ifdef __cplusplus
}
#endif
