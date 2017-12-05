#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
typedef long long ll;

string root(map<string,string>&adj, string i)
{
	while (adj[i] != i)
	{

		adj[i] = adj[adj[i]];
		i = adj[i];

	}

	return i;
}
int wUnion(map<string, string>&adj, map<string, int>&size, string a, string b)
{
	string root_A = root(adj,a);
	string root_B = root(adj,b);
	string temp;
	if (root_A!=root_B)
	{
		if (size[root_A] < size[root_B])
	{
		adj[root_A] = adj[root_B];
		size[root_B] += size[root_A];
		return size[root_B];
	}
	else
	{
		adj[root_B] = adj[root_A];
		size[root_A] += size[root_B];
		return size[root_A];
	}

	}
	return size[root_A];
	
}
int main()
{
	ll tc;
	cin >> tc;
	while (tc--)
	{
		map<string,string>adj;
		map<string, int>size;
		
		long long  m;
		string x, y;
		cin >>  m;
		

		for (long long i = 0; i < m; i++)
		{
			ll ans = 0;
			cin >> x >> y;
			if (!adj.count(x))
			{
				adj[x] = x;
				size[x] = 1;
			}
			if (!adj.count(y))
			{
				adj[y] = y;
				size[y] = 1;
			}
		ans=wUnion(adj, size, x, y);
			
			

		
		
			cout << ans<<  endl;
			//cout << connectedComp(adj, visited,x) << endl;
		}
		

	}
	return 0;
}