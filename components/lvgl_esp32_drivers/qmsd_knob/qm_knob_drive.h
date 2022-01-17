#ifndef QM_KNOB_DRIVE
#define QM_KNOB_DRIVE

#define GPIO_DIR 17
#define GPIO_DSP1 16
#define GPIO_BTN 7
#define ESP_INTR_FLAG_DEFAULT 0

void knob_init(int dir_io , int dsp_io , int btn_io);
int knob_get_value(void);
int knob_get_press(void);

#endif