#include<iostream>
using namespace std;
typedef long long ll;
ll n, m, x, y, ans, num = 0;
ll arr[50010];
int find(int x)
{
	if (arr[x] == x)
		return x;
		
	return arr[x] = find(arr[x]);
}
void solve(int x, int y)
{
	int px=0, py=0;
	px = find(x);
	py = find(y);

	if (px != py)
	{
		arr[px] = py;
		ans--;
	}
}
int main()
{
	while (1)
	{
		num++;
		cin >> n >> m;
		if (0 == n && 0 == m)break;
		for (ll j = 1; j <= n; j++)arr[j] = j;
		ans =n;
		for (ll i = 0; i < m; i++)
		{
			cin >> x >> y;
			solve(x, y);
			
		}
		
		cout << "Case "<<num<<": "<<ans << endl;
	}
	return 0;
}