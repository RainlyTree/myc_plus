#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

void mkdir(set<string>& fin)
{
	for (auto e : fin)
	{
		cout << "mkdir " << "-p " << e << endl;
	}
}

int main()
{
	int x = 1;
	int num = 0;
	while (cin >> num)
	{
		set<string> fin;
		cin.get();
		for (int i = 0; i < num; ++i)
		{
			bool flag = false;
			string str = "";
			getline(cin, str);
			for (auto e : fin)
			{
				int idx = e.find(str);
				string tmp = e;
				if (idx != string::npos && idx == 0 && tmp[str.size()] == '/')
				{
					flag = true;
					break;
				}
				idx = str.find(e);
				tmp = str;
				if (idx != string::npos && idx == 0 && tmp[e.size()] == '/')
				{
					fin.insert(str);
					fin.erase(e);
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				fin.insert(str);
			}
		}
		if (x == 1)
		{
			mkdir(fin);
			++x;
		}

		else
		{
			cout << endl;
			mkdir(fin);
		}
	}
}