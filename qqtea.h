/* 参考： https://github.com/Mrs4s/MiraiGo/blob/master/binary/tea.go */

/*
usage:
#include <stdio.h>
#include <assert.h>
#include "qqtea.h"

int main()
{
    int32_t i;
    uint32_t encode_buf_len,decode_buf_len;
    const unsigned char  key[] = {120, 76, 249, 219, 21, 206, 98, 255, 135, 49, 196, 249, 195, 140, 250, 13};
    const unsigned char buf[] = {0, 3, 31, 3, 90, 125, 0, 0, 0, 5, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 224, 243, 85, 220, 6, 100, 0, 0, 0, 0, 1, 66, 151, 244, 75, 19, 149, 82, 53, 36, 91, 36, 151, 57, 157, 122, 147, 41, 35, 190, 132, 225, 108, 214, 174, 82, 144, 73, 241, 241, 187, 233, 235, 0, 0, 0, 0, 1, 70, 96, 30, 211, 198, 36, 22, 191, 202, 162, 158, 158, 184, 154, 210, 78, 32, 2, 149, 246, 0, 0, 0, 1, 0, 0};
    unsigned char * encode_buf = qqtea_encode(key,buf,sizeof(buf),&encode_buf_len);
    assert(encode_buf);
    unsigned char * decode_buf = qqtea_decode(key,encode_buf,encode_buf_len,&decode_buf_len);
    assert(decode_buf);
    assert(decode_buf_len == sizeof(buf));
    for(i = 0;i < decode_buf_len;++i)
    {
        assert(decode_buf[i] == buf[i]);
    }
    printf("test ok\n");
    return 0;
}
*/

#ifndef __QQTEA_H__
#define __QQTEA_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

/*
 * 描述:用qqtea来加密
 * 参数key:长度必须为16
 * 参数out_buf_len:加密后的数据长度
 * 返回值:加密后的数据，使用qqtea_free来释放
 */
    unsigned char *qqtea_encode(const unsigned char *key, const unsigned char *buffer, uint32_t len, uint32_t *out_buf_len);

/*
 * 描述:用qqtea来解密
 * 参数key:长度必须为16
 * 参数out_buf_len:解密后的数据长度
 * 返回值:解密后的数据，使用qqtea_free来释放
 */
    unsigned char *qqtea_decode(const unsigned char *key, const unsigned char *buffer, uint32_t len, uint32_t *out_buf_len);

/* 
 * 描述:释放加解密函数返回指针指向的内存(空指针安全)
 */
    void qqtea_free(unsigned char *buffer);

#ifdef __cplusplus
}
#endif
#endif
