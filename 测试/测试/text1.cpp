// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> name;
	string f1, f2;
	while (getline(cin, f1))
	{
		getline(cin, f2);
		string tmp = "";
		for (int i = 0; i < f1.size(); ++i)
		{
			if (f1[i] == '\"')
			{
				++i;
				while (f1[i] != '\"')
				{
					tmp += f1[i];
					++i;
				}
				name.push_back(tmp);
				tmp = "";
				continue;
			}
			if (f1[i] != ',')
			{
				tmp += f1[i];
			}
			else if (tmp != "")
			{
				name.push_back(tmp);
				tmp = "";
			}
		}
		int i;
		for (i = 0; i < name.size(); ++i)
		{
			if (name[i].compare(f2) == 0)
			{
				cout << "Ignore" << endl;
				break;
			}	
		}
		if (i == name.size())
			cout << "Important!" << endl;
	}
	return 0;
}