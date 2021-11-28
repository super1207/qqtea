# qqtea
C语言实现的QQ TEA 加解密

## test
```c
#include <stdio.h>
#include <assert.h>
#include "qqtea.h"

int main()
{
    uint32_t i;
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
    qqtea_free(encode_buf);
    qqtea_free(decode_buf);
    printf("test ok\n");
    return 0;
}
```
## 参考
[https://github.com/Mrs4s/MiraiGo/blob/master/binary/tea.go](https://github.com/Mrs4s/MiraiGo/blob/master/binary/tea.go)
