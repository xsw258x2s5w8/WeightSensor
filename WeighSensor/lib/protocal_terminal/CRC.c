/*
 * Queue.c
 *
 *  Created on: May 2, 2017
 *      Author: software school
 */

#include "CRC.h"

/**
 * ²é±í·¨
 */
uint CRC32Software(unsigned char * pData, int Length)
{
    	uint uCRCValue;
    	unsigned char chtemp;
    	int i,uSize;

    	uSize = Length/4;
    	uCRCValue = 0xFFFFFFFF;
    	while (uSize --)
    	{
    			for(i = 3;i >= 0;i--)
    			{
    					chtemp=*(pData + i);
    					uCRCValue = Crc32Table[((uCRCValue>>24)&0xFF) ^ chtemp] ^ (uCRCValue<<8);
    			}
    			pData += 4;
    	}
    	return uCRCValue;
}
