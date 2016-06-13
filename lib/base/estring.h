#ifndef __E_STRING__
#define __E_STRING__

#include <string>
#include <stdarg.h>
#include <stdio.h>
#include "eerror.h"

std::string buildShortName( const std::string &str );

int strnicmp(const char*, const char*, int);

std::string getNum(int num, int base=10);

std::string convertDVBUTF8(const unsigned char *data, int len, int table=1, int tsidonid=1); // with default ISO8859-1 / Latin1
std::string convertLatin1UTF8(const std::string &string);
int isUTF8(const std::string &string);
unsigned int truncateUTF8(std::string &s, unsigned int newsize);

std::string removeDVBChars(const std::string &s);
void makeUpper(std::string &s);
std::string replace_all(const std::string &in, const std::string &entity, const std::string &symbol);

inline std::string convertDVBUTF8(const std::string &string, int table=1, int tsidonid=1) // with default ISO8859-1 / Latin1
{
	return convertDVBUTF8((const unsigned char*)string.c_str(), string.length(), table, tsidonid);
}

std::string urlDecode(const std::string &s);
static unsigned char UTF[2048]; //转码后的unicode 16字符串
static bool FORCE_GBK = false;
const static int GBK2_OFFSET = 2; //GBK/2的偏移地址,头两个字符是BOM(0xFFFE)
const static int GBK3_OFFSET = 2 + 6763 * 2 + 5 * 2; //GBK/3的偏移地址,GBK/2有6763个字符
const static int GBK4_OFFSET = 13528 + 6080 * 2; //GBK/4的偏移地址,GBK/3有6080个字符
const static int GBK1_OFFSET = 41806 + 5 * 2; // GBK/4即gb2312的符号的偏移地址
const static int GBK5_OFFSET = 41806 + 846 * 2 + 5 * 2; // GBK5符号的偏移地址
int ConvertGBK2Unicode(unsigned char* dest, int src_size, unsigned char* src);
int ConvertBig52Unicode(unsigned char* dest, int src_size, unsigned char* src);
std::string ConvertUnicode2UTF8(const unsigned char *data, int len); //input BIGEND Unicode
bool isUTF8(const void* pBuffer, size_t size);
void printDVBchar(const std::string &string);
std::string getOSDcountryCode();
	
#endif // __E_STRING__
