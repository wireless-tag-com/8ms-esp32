#ifndef ENCRYPT_8MS_H
#define ENCRYPT_8MS_H


/**
 * @brief This function need to be called at least once and it is defaultly called in 8ms project.
 * 
 * @return true 
 * @return false 
 */
bool custom_enrypt_qmsd_init(void);

/**
 * @brief Can be called after init,this func will not do any calculation ,if certification are confirmed in init func it will always return true.
 * 
 * @return true 
 * @return false 
 */
bool custom_encrypt_qmsd_get_ret(void);

#endif