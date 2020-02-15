#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"file_manager.h"


void test()
{
	file_manager file;
	std::string path;
	std::cout << "input your scanner path : " << std::endl;
	std::cin >> path;
	std::cout << std::endl;
	file.scanning(path);
	file.showAllFile();
	file.showFile_MD5();
	std::string str;
	std::cin >> str;
	//file.delete_MD5(str);
	//file.delete_name(str);
	//file.deleteAllSame();
	//file.delete_match_name(str);
	file.clear_match_name(str);
}

int main()
{
	test();
}