#include<iostream>
#include<fstream>
#include"MD5.h"
using namespace std;

//固定值(不要在头文件中定义  防止多个头文件)
size_t MD5::s[] =
{
7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

void MD5::reset()
{
	//初始化  A B C D
	count[0] = count[1] = 0;
	state[0] = 0x67452301;
	state[1] = 0xefcdab89;
	state[2] = 0x98badcfe;
	state[3] = 0x10325476;

	memset(chunk, 0, 64);

	count[0] = count[1] = 0;
}

void MD5::MD5Init()
{
	//初始化k
	for (int i = 0; i < 64; ++i)
	{
		k[i] = static_cast<UINT4>(abs(sin(i + 1)) * pow(2, 32));
	}
	reset();
}

MD5::MD5()
{
	MD5Init();
}

void MD5::MD5Update(UINT4* chunk)
{
	int a = state[0], b = state[1], c = state[2], d = state[3];
	UINT4 f, g;
	for (int i = 0; i < 64; ++i)
	{
		if (0 <= i && i <= 15)
		{
			f = F(b, c, d);
			g = i;
		}
		else if (16 <= i && i <= 31)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (32 <= i && i <= 47)
		{
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		//进行更新
		
		int tmp = d;
		d = c;
		c = b;
		b = b + shift(chunk[g] + a + f + k[i]  , s[i]);
		a = tmp;

	}
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
}

void MD5::MD5Final()
{
	//必然要填充一个byte
	//到达末尾填充一个 1000 0000
	char*p = chunk + count[1];
	*p++ = 0x80;
	//查看最后一个块大小
	int last_info = TRUNK_INFO - count[1] - 1;
	//如果剩余字节不够8个字节
	if (last_info < 8)
	{
		//末尾全部置0
		memset(p, 0, last_info);
		//处理当前数据块
		MD5Update((UINT4*)chunk);
		//将数据块清0
		memset(chunk, 0, TRUNK_INFO);
	}
	else
	{
		//给末尾全部置0
		memset(p, 0, last_info);
	}
	//count[0]记录总长度
	unsigned long long totalBits = count[0];
	//获取bit位长度
	totalBits *= 8;
	//变成long long 一个8字节 到7末尾填充长度信息
	((unsigned long long*) chunk)[7] = totalBits;
	//最后更新一次数据块
	MD5Update((UINT4*)chunk);
}

string MD5::change16(UINT4 n)
{
	static string strMap = "0123456789abcdef";
	string ret;
	for (int i = 0; i < 4; ++i)
	{
		//一次获得一个byte
		int cur = (n >> (i * 8)) & 0xff;

		string curStr;
		//高位在前
		curStr += strMap[cur / 16];
		//低位在后
		curStr += strMap[cur % 16];
		ret += curStr;
	}
	return ret;
}

std::string MD5::getStingMD5(const string& str)
{
	//判断如果为空 直接返回
	if (str.empty() == 1)
	{
		return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));
	}
	//获取字符总长度
	count[0] = str.size();
	UINT4 num = count[0] / TRUNK_INFO;
	const char* ptr = str.c_str();
	for (int i = 0; i < num; ++i)
	{
		//每次将一个块的内容进行更新
		memcpy(chunk, ptr + i * TRUNK_INFO, TRUNK_INFO);
		MD5Update((UINT4*)chunk);
	}
	//获取最后一个数据块的大小
	count[1] = count[0] % TRUNK_INFO;
	//获取最后一部分数据
	memcpy(chunk, ptr + num * TRUNK_INFO,count[1] );
	MD5Final();
	return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));;
}

std::string MD5::getFile(const char* File)
{
	ifstream file(File, ifstream::binary);
	if (!file.is_open())
	{
		cout << File;
		perror(":not have is file");
		return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));
	}

	////IO次数少  运算速率提升
	//while (!file.eof())
	//{
	//	file.seekg(0, file.end);
	//	UINT4 len = file.tellg();
	//	file.seekg(0, file.beg);
	//	char* Date = new char[len];
	//	file.read(Date, len);
	//}

	//一次读取一块数据
	while (!file.eof())
	{
		file.read(chunk, TRUNK_INFO);
		//最后一块可能不足一个块大小
		if (TRUNK_INFO != file.gcount())
		{
			break;
		}
		count[0] += TRUNK_INFO;
		MD5Update((UINT4*)chunk);
	}
	//更新最后一块数据块
	count[1] = file.gcount();
	count[0] += count[1];
	MD5Final();
	return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));
}

