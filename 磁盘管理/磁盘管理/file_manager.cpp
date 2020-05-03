#define _CRT_SECURE_NO_WARNINGS
#include"file_manager.h"
#include"file_tool.h"
#include<algorithm>
#include<set>
#include<fstream>

bool file_manager::write_in_file()
{
	std::set<std::string> sort_file;
	for (auto& e : file)
	{
		sort_file.insert(e);
	}
	std::cout << "input your path" << std::endl;
	std::string path;
	std::cin >> path;
	for (auto& e : sort_file)
	{
		std::ofstream outfile;
		outfile.open(path, std::ios::out | std::ios::app);
		outfile << e << ';' << std::endl;
		outfile.close();
	}
	return true;
}


//对当前盘下内容扫描
void file_manager::scanning(const std::string & path)
{
	//将原来的文件清空
	file.clear();

	//将文件名放入set中
	search_director(path, file);
	MD5_File();
	File_MD5();
}

//填充MD5 ---> file
void file_manager::MD5_File()
{
	//进行清理
	Md5_Name.clear();
	for (const auto& f : file)
	{
		//重置md5值  并计算新的MD5值放入
		md5.reset();
		Md5_Name.insert(make_pair(md5.getFile(f.c_str()), f));
	}
}

//填充file -->MD5(找有重复的文件)
void file_manager::File_MD5()
{
	Name_MD5.clear();

	auto it = Md5_Name.begin();
	while (it != Md5_Name.end())
	{
		//判断是否大于一个
		if (Md5_Name.count(it->first) > 1)
		{
			//获取重复的范围
			auto str = Md5_Name.equal_range(it->first);
			auto begin = str.first;
			while (begin != str.second)
			{
				Name_MD5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			it = begin;
		}
		else
		{
			++it;
			//it = Md5_Name.erase(it);
		}
	}
}

//相同文件名删除
void file_manager::delete_name(const std::string& name)
{
	if (Name_MD5.count(name) == 0)
	{
		std::cout << "the file is not exist" << std::endl;
		return;
	}
	//因为Name_Md5中只存放有重复的元素  所有不为0 肯定大于1
	std::string str = Name_MD5[name];

	auto it = Md5_Name.equal_range(str);
	auto beg = it.first;
	while (beg != it.second)
	{
		if (beg->second != name)
		{
			file.erase(beg->second);
			Name_MD5.erase(beg->first);
			delete_file(beg->second.c_str());
		}
		++beg;
	}

	// 删除MD5_Name中的映射
	beg = it.first;
	Md5_Name.erase(beg, it.second);
	Md5_Name.insert(make_pair(str, name));
}


//相同MD5值删除
void file_manager::delete_MD5(const std::string& md5)
{
	if (Md5_Name.count(md5) == 0)
	{
		std::cout << "the file is not exist" << std::endl;
		return;
	}
	auto it = Md5_Name.equal_range(md5);
	auto beg = it.first;
	//存储第一份不被删除
	++beg;
	while (beg != it.second)
	{
		//需要删除file 与 Name_MD5中的映射
		file.erase(beg->second);
		Name_MD5.erase(beg->second);
		delete_file(beg->second.c_str());
		++beg;
	}
	//删除MD5_Name中的映射
	beg = it.first;
	++beg;
	Md5_Name.erase(beg, it.second);
}

void file_manager::deleteAllSame()
{
	//由于通过Name_Md5还要去Md5_Name中找Md5码  
	//所以直接遍历file,每一次delete会更新file
	//减少搜索时间
	auto it = file.begin();
	while (it != file.end())
	{
		delete_name(*it);
		++it;
	}
	std::cout << "ALL Same File is Delete" << std::endl;
}


//删除包含有matchName的文件
void file_manager::delete_match_name(const std::string& matchName)
{
	//删除特定名字的重复文件  与上述AllSame函数功能相似
	auto it = file.begin();
	while (it != file.end())
	{
		if ((*it).find(matchName) != 0)
			delete_name(*it);
		++it;
	}
}

void file_manager::clear_match_name(const std::string& matchName)
{
	//先去Name_Md5中删除所有的副本 再回到file中删除原本
	delete_match_name(matchName);
	auto it = file.begin();
	while(it != file.end())
	{
		if ((*it).find(matchName) != 0)
		{
			delete_file((*it).c_str());
			it = file.erase(it);
		}
		else
		{
			++it;
		}
	}
}


void file_manager::showAllFile()
{
	auto it = file.begin();
	while (it != file.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	//显示总的文件数
	std::cout << "file number is :" << file.size() << std::endl;
}


void file_manager::showFile_MD5()
{
	//内容相同的文件显示在一起
	auto it = Md5_Name.begin();
	while (it != Md5_Name.end())
	{
		//显示文件的个数
		int index = 1;
		auto pairIt = Md5_Name.equal_range(it->first);
		auto tmp = pairIt.first;
		std::cout << "MD5:" << it->first << std::endl;
		while (tmp != pairIt.second)
		{
			std::cout << "第" << index << "个文件：";
			std::cout << tmp->second << std::endl;
			++index;
			++tmp;
		}
		std::cout << "the same file is :" << index - 1 << std::endl;
		it = pairIt.second;
	}
}

bool file_manager::Find_File(const std::string& md5)
{
	return true;
}