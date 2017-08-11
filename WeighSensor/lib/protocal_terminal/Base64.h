#ifndef BASE64_H_
#define BASE64_H_

#define maxBaseByte 256

unsigned int base64Decode(unsigned char *value,int len);
unsigned char* base64Encode(unsigned char *value,int len);

#endif
