#ifndef __QMSD_LANG_H__
#define __QMSD_LANG_H__

#ifdef __cplusplus
extern "C"
{
#endif

int qmsd_lang_set(const char *lang);
char *qmsd_lang_get(void);
void qmsd_lang_clear(void);
int qmsd_lang_init(const char *lang_str);
const char *qmsd_lang_trans(const char *key, const char *def_val);
void qmsd_lang_deinit(void);

#ifdef __cplusplus
}
#endif

#endif
