#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h>
#include"file_manager.h"
using std::cin;
using std::cout;
using std::endl;

void menu()
{
	/*cout << "*********************************" << endl;
	cout << "*************磁盘清理************" << endl;
	cout << "*********************************" << endl;
	Sleep(1000);
	system("cls");*/
	cout << "*********************************" << endl;
	cout << "1.scanner  2.show all 3.show same" << endl;
	cout << "4.delete by name  5.delete by md5" << endl;
	cout << "6.delete all same file by name" << endl;
	cout << "7.delete match name file " << endl;
	cout << "8.clear all you want to delete" << endl;
	cout << "*********************************" << endl;
	cout << "0.exit this system" << endl;
}

void test()
{
	file_manager file;
	int num;
	do
	{
		menu();
		cout << "choose your action:" << endl;
		cin >> num;
		//回车需要被回收
		//char tmp;
		//cin >> tmp;
		switch (num)
		{
		case 0:
			exit;
		case 1:
		{
			cout << "input path" << endl;
			std::string path;
			cin >> path;
			file.scanning(path);
			system("cls");
			break;
		}
		case 2:
		{
			file.showAllFile();
			break;
		}
		case 3:
		{
			file.showFile_MD5();
			break;
		}
		case 4:
		{
			cout << "input name:";
			std::string name;
			cin >> name;
			file.delete_name(name);
			break;
		}
		case 5:
		{
			cout << "input MD5:";
			std::string MD5;
			cin >> MD5;
			file.delete_MD5(MD5);
			break;
		}
		case 6:
		{
			file.deleteAllSame();
		}
		case 7:
		{
			cout << "input the file name:";
			std::string matchName;
			cin >> matchName;
			file.delete_match_name(matchName);
		}
		case 8:
		{
			cout << "input the file name:";
			std::string matchName;
			cin >> matchName;
			file.clear_match_name(matchName);
		}
		default:
			break;
		}
	} while (num != 0);
}

int main()
{
	test();
}