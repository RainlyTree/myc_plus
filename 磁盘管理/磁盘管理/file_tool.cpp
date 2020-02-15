#define _CRT_SECURE_NO_WARNINGS
#include"file_tool.h"

void search_director(const std::string& path, std::unordered_set<std::string>& File)
{
	//count用来计算文件的数量
	int count = 0;
	std::string match_file = path + "\\" + "*.*";
	_finddata_t file_attribute;
	long handle = _findfirst(match_file.c_str(), &file_attribute);
	if (handle == -1)
	{
		perror("failed");
		return;
	}
	//_findnext == 0表示还有
	do
	{
		//如果是目录
		if (file_attribute.attrib & _A_SUBDIR)
		{
			//不是他的当前目录 并且不去它的上层目录
			if (strcmp(file_attribute.name, ".") != 0 && strcmp(file_attribute.name, "..") != 0)
				search_director(path + "\\" + file_attribute.name, File);
		}
		else
		{
			//显示它的文件绝对路径，不然可能出现一样的文件名
			File.insert(path + "\\" + file_attribute.name);
			++count;
		}
	} while (_findnext(handle, &file_attribute) == 0);
	_findclose(handle);
}


void delete_file(const char* file_name)
{
	if (remove(file_name) == 0)
	{
		std::cout << "delete file success" << std::endl;
	}
	else
	{
		std::cout << "some problem arise, you need to see delete_file f(x)" << std::endl;
	}
}