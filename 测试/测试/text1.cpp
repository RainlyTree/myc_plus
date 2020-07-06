#include<iostream>
#include<new>
#include<cstddef>
#include<cstdlib>
#include<climits>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	vector<vector<int>> fin(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
	int row = obstacleGrid.size();
	int col = obstacleGrid[0].size();
	for (int i = 0; i < row; ++i)
	{
		cout << obstacleGrid.size() << obstacleGrid[0].size();
		for (int j = 0; j < col; j++)
		{
			if (i == 0)
			{
				if (j == 0)
					fin[i][j] = 1;
				else if (obstacleGrid[i][j] == 1)
					fin[i][j] = 0;
				else
					fin[i][j] = fin[i][j - 1];
			}
			else if (j == 0)
			{
				if (i == 0)
					fin[i][j] = 1;
				else if (obstacleGrid[i][j] == 1)
					fin[i][j] = 0;
				else
					fin[i][j] = fin[i - 1][j];
			}
			else
			{
				if (obstacleGrid[i][j] == 1)
					fin[i][j] = 0;
				else
					fin[i][j] = fin[i - 1][j] + fin[i][j - 1];
			}
		}

	}
	return fin[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
}
int main(int argc, char* argv[])
{
	vector<vector<int>> fin = { {0,0} };
	uniquePathsWithObstacles(fin);
	return 0;
}