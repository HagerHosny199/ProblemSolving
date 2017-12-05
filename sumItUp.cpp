#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int t, n;
int arr[10001];
int num = 0;
vector<int>ans[10001];
void backtrack(int i,int sum)
{
	if (sum == t)
	{
		ans[num + 1] = ans[num];
		num++;
		return;
	}
	for (int j = i; j < n; j++)
	{
		if (sum + arr[j] <= t)
		{
			sum += arr[j];
			ans[num].push_back(arr[j]); //do

			backtrack(j + 1, sum);     //rec

			sum -= arr[j];             //undo
			ans[num].pop_back();

		}
	}
	
}
void print(vector<int>x)
{
	for (int i = 0; i < x.size(); i++)
		if (i + 1 == x.size())
			cout << x[i] << endl;
		else
		cout << x[i] << "+";
}
bool cmp(vector<int> a, vector<int> b)
{
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == b[i]) continue;
		return a[i] > b[i];
	}
	return a.size() > b.size();
}
int main()
{
	while (1)
	{
		cin >> t >> n;
		if (!t&&!n)
			break;
		for (int i = 0; i < n; i++)
		cin >> arr[i];
		num = 0;
		for (auto &vec : ans) vec.clear();
		backtrack(0,0);
		printf("Sums of %d:\n", t);
		if (num == 0)
			cout << "NONE\n";
		else
		{
			sort(ans, ans + num, cmp);
			print(ans[0]);
			for (int i = 1; i < num; i++)
			{
				if (ans[i] != ans[i - 1])
					print(ans[i]);
			}
		}


	}
	return  0;
}