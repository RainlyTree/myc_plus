// write your code here cpp
#include<iostream>
#include<vector>
using namespace std;

void test(vector<vector<char>>& fin)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (fin[i][j] == '.')
				continue;
			else
			{
				int tmpi = i;
				int tmpj = j;
				int num = 1;
				//向右
				while (tmpj + 1 < 20 && fin[tmpi][tmpj] == fin[tmpi][tmpj + 1])
				{
					++tmpj;
					++num;
					if (num == 5)
					{
						cout << "Yes" << endl;
						return;
					}
				}
				num == 0;
				//向下
				while ((tmpi + 1) < 20 && fin[tmpi][tmpj] == fin[tmpi + 1][tmpj])
				{
					++tmpi;
					++num;
					if (num == 5)
					{
						cout << "Yes" << endl;
						return;
					}
				}
				num == 0;
				//右下
				while (tmpi + 1 < 20 && tmpj + 1 < 20 && fin[tmpi][tmpj] == fin[tmpi + 1][tmpj + 1])
				{
					++tmpj;
					++tmpi;
					++num;
					if (num == 5)
					{
						cout << "Yes" << endl;
						return;
					}
				}
				num == 0;
				//左下
				while (tmpi + 1 < 20 && tmpj - 1 >= 0 && fin[tmpi][tmpj] == fin[tmpi + 1][tmpj - 1])
				{
					--tmpj;
					++tmpi;
					++num;
					if (num == 5)
					{
						cout << "Yes" << endl;
						return;
					}
				}
			}
		}
	}

	cout << "No" << endl;
}

int main()
{
	vector<vector<char>> fin(20, vector<char>(20));
	char c;
	while ((c = getchar()) != EOF)
	{
		ungetc(c, stdin);
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				c = getchar();
				fin[i][j] = c;
			}
			getchar();
		}
		test(fin);
	}
	return 0;
}