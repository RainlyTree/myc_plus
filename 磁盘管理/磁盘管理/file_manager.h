#pragma once
#include<fstream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include"MD5.h"

class file_manager
{
public:
	//对当前盘下内容扫描
	void scanning(const std::string & path);
	//填充MD5 ---> file
	void MD5_File();
	//填充file -->MD5
	void File_MD5();

	//相同文件名删除
	void delete_name(const std::string& name);
	//相同MD5值删除
	void delete_MD5(const std::string& md5);
	//删除所有重复的文件
	void deleteAllSame();
	//删除包含有matchName的文件
	void delete_match_name(const std::string& matchName);

	//删除所有有matchName的文件(一份都不保留)
	void clear_match_name(const std::string& matchName);

	//显示所有文件
	void showAllFile();
	//显示有重复文件
	void showFile_MD5();
	void showMD5();

	//判断是是否有这个文件
	bool Find_File(const std::string& md5);

	bool write_in_file();
private:
	//存放所有文件的绝对路径
	std::unordered_set<std::string> file;
	//存放所有文件的md5--->name的映射
	std::unordered_multimap<std::string, std::string> Md5_Name;

	//存放重复文件
	std::unordered_map<std::string, std::string> Name_MD5;
	
	MD5 md5;
};
