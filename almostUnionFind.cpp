#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
int adj[200001], size[200001], mapped[200001];
long long roots[200001];
void init(int n) {
	static int i;
	for (i = 0; i <= n; i++) {
		adj[i] = i, roots[i] = 0, size[i] = 1;
		mapped[i] = i;
	}
}
int root(int x) {
	return adj[x] == x ? x : adj[x] = root(adj[x]);
}
void Union(int x, int y, int i, int j) {
	if (x == y)
		return;
	roots[x] += roots[y];
	size[x] += size[y];
	roots[y] = 0;
	roots[y] = 0;
	adj[y] = x;
}
int main() {
	int n, m, op,rootx, rooty, t, x, y;
	while (scanf("%d %d", &n, &m) == 2) {
		init(n + m);
		for (int i = 0; i <= n; i++)
			roots[i] = i;
		while (m--) {
			scanf("%d %d", &op, &x);
			if (op == 3) {
				t =root(mapped[x]);
				printf("%d %lld\n", size[t], roots[t]);
			}
			else if (op == 2) {
				scanf("%d", &y);
				rootx = root(mapped[x]);
				rooty = root(mapped[y]);
				if (rootx != rooty) {
					roots[rootx] -= x, size[rootx]--;
					mapped[x] = ++n;
					roots[mapped[x]] = x;
					size[mapped[x]] = 1;
					Union(root(mapped[x]), root(mapped[y]), x, y);
				}
			}
			else {
				scanf("%d", &y);
				Union(root(mapped[x]), root(mapped[y]), x,y);
			}
		}
	}
	return 0;
}