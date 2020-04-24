#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<int> vec[], vector<bool> &vis, int u, int search)
{
    vis[u]=true;
    // int tmp=u;
    for (int i=0;i<vec[u].size();i++)
    {
        if (search==vec[u][i]) return true;
        if (!vis[vec[u][i]])
        if (isCycle(vec, vis, vec[u][i], search)) return true;
    }
    return false;
}

bool dfs(vector<int> vec[], vector<bool> &vis, int n)
{
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        if (isCycle(vec, vis, i, i)) return true;
    }
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i;
	cin>>n>>m;
	vector<int> vec[n+1];
	for (i=0;i<m;i++)
	{
	    int u, v;
	    cin>>u>>v;
	    vec[u].push_back(v);
	}
	vector<bool> vis(n+1, false);
	cout<<dfs(vec, vis, n);
	return 0;
}
