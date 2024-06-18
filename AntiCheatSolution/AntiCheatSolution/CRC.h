#ifndef CHECKSUM_H
#define CHECKSUM_H


// 다항식 : x^32 + x^26 + x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1
// 32/31/30/29/28/27/26/25/24/23/22/21/20/19/18/17/16/15/14/13/12/11/10/9/8/7/6/5/4/3/2/1/0
//  1/ 0/ 0/ 0/ 0/ 0/ 1/ 0/ 0/ 1/ 1/ 0/ 0/ 0/ 0/ 0/ 1/ 0/ 0/ 0/ 1/ 1/ 1/0/1/1/0/1/1/0/1/1/1 
#define CRC32_POLYNOMIAL 0x04c11db7 //crc32 다항식을 hex & reverse = edb88320
#define CRC32BUFSZ 1024

class CheckSum {

public:

	void CRCInit(void);
	void DetectCRC();
	unsigned long FileCRC(const char* sFileName);
	unsigned long FullCRC(unsigned char* sData, unsigned long ulLength);
	void PartialCRC(unsigned long* ulInCRC, unsigned char* sData, unsigned long ulLength);

private:

	unsigned long Reflect(unsigned long ulReflect, char cChar);
	unsigned long ulTable[256];
};

extern CheckSum Check;

#endif