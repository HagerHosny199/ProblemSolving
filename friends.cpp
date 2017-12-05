#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<int>top;
void dfs(long long node, vector<vector<int>>&adj, bool(&visited)[300001],ll &count)
{
	visited[node] = true;
	for (long long i = 0; i < adj[node].size(); i++)
	{
		int child = adj[node][i];
		if (!visited[child])
		{
			count++;
			dfs(child,adj,visited,count);


		}

	}
	top.push_back(node);
}
int connectedComp(vector<vector<int>>&adj,bool (&visited)[300001],ll n)
{
	ll count = 0,t=0;

	for (ll i = 1; i <= n; i++)
	{
		t = 0;
		if (!visited[i])
		{
			dfs(i, adj, visited,t);
			t++;
			if (t > count)
				count = t;
		}
		
	}
	return count;
}
int main()
{
	ll tc;
	cin >> tc;
	while (tc--)
	{
		vector<vector<int>>adj;
		bool visited[300001];
		long long n, m, x, y;
		cin >> n >> m;
		
		for (long long i = 0; i <n + 2; i++)
		{
			visited[i] = 0;
			vector<int> row;
			adj.push_back(row);
		}
		for (long long i = 0; i < m; i++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		cout<<connectedComp(adj,visited,n)<<endl;

	}
	return 0;
}