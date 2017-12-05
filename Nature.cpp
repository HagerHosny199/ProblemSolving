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
void wUnion(map<string, string>&adj, map<string, int>&size, string a, string b)
{
	string root_A = root(adj,a);
	string root_B = root(adj,b);
	//string temp;
	if (root_A!=root_B)
	{
		if (size[root_A] < size[root_B])
	{
		adj[root_A] = adj[root_B];
		size[root_B] += size[root_A];
		//return size[root_B];
	}
	else
	{
		adj[root_B] = adj[root_A];
		size[root_A] += size[root_B];
	//return size[root_A];
	}

	}

	
}
int main()
{

	while (1)
	{
		map<string,string>adj;
		map<string, int>size;
		
		long long  n,m,max=0;
		string x, y,temp;
		cin >> n >>m;
		if (n == 0 && m == 0)break;
		for (ll i = 0; i < n; i++){
			cin >> temp;
			size[temp] = 1;
		}

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
		wUnion(adj, size, x, y);
		
			//cout << ans<<  endl;
			//cout << connectedComp(adj, visited,x) << endl;
		}
		

			for (map<string, int >::const_iterator it = size.begin();
				it != size.end(); ++it)
		{
			if (it->second > max)
				max = it->second;
		}
			cout << max<<endl;
	}
	return 0;
}