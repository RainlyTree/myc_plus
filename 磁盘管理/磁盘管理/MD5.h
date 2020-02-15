#pragma once
#include<string>
typedef unsigned char *POINTER;
typedef unsigned int UINT4;
#define TRUNK_INFO 64


class MD5
{
public:
	UINT4 F(UINT4 x, UINT4 y, UINT4 z)
	{
		return (x & y) | ((~x) & z);
	}
	UINT4 G(UINT4 x, UINT4 y, UINT4 z)
	{
		return (x & z) | (y & (~z));
	}
	UINT4 H(UINT4 x, UINT4 y, UINT4 z)
	{
		return x ^ y ^ z;
	}
	UINT4 I(UINT4 x, UINT4 y, UINT4 z)
	{
		return (y) ^ (x | (~z));
	}
	UINT4 shift(UINT4 number, int shift_number)
	{
		return (number << shift_number) | (number >> (32 - shift_number));
	}
	MD5();
	void MD5Init();

	void reset();

	//这样在后面块的计算无需做偏移
	void MD5Update(UINT4* chunk);
	
	void MD5Final();
	std::string change16(UINT4 n);
	std::string getStingMD5(const std::string& str);
	std::string getFile(const char* File);

private:
	UINT4 state[4];				//存放 A B C D
	UINT4 count[2];				//存放总的大小与最后的位置
	char chunk[TRUNK_INFO];		//一个数据块
	UINT4 k[64];				//处理使用
	static size_t s[];			//左移偏量
};



