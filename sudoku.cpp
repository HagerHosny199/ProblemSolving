#include<iostream>
#include <cstdio>
using namespace std; 
int grid[9][9];
bool row[9][10], col[9][10], sq[9][10];
int n,N;
bool solved = false;
bool available(int r, int c)
{
	if (r == N&&c == 0)
		return false;
	return true;
}
bool safe(int r, int c, int num)
{
	if (row[r][num] || col[c][num] || sq[r / n*n + c / n][num])
		return false;
	return true;
}
void solve(int r,int c)
{
	if (solved)return;
	if (!available(r, c))
	{
		solved = true;
		return;
	}
	if (grid[r][c] != 0)
		solve(c == N - 1 ? r + 1 : r, c == N - 1 ? 0 : c + 1);
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (safe(r, c, i))
			{
				grid[r][c] = i; //do
				row[r][i] = col[c][i] = sq[r / n*n + c / n][i] = true;
				solve(c == N - 1 ? r + 1 : r, c == N - 1 ? 0 : c + 1);
					if (solved)
					return ; //el path kaml ll a5r 
				 //undo 
				row[r][i] = col[c][i] = sq[r / n*n + c / n][i] = false;
			}
			grid[r][c] = 0;
		}
	
	}

}
void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	while (scanf_s("%d", &n) == 1)
	{
		 N = n*n;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> grid[i][j];
				row[i][j + 1] = col[i][j + 1] = sq[i][j + 1] = false;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (grid[i][j] == 0) continue;
				row[i][grid[i][j]] = col[j][grid[i][j]] = sq[i / n*n + j / n][grid[i][j]] = true; //r=4 c=6
			}
		}
		solved = 0;
		solve(0, 0);
		if (solved)
		print();
		else
			cout << "NO SOLUTION" << endl;

	}

	return 0;
}