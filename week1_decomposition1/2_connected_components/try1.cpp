#include <bits/stdc++.h>
using namespace std;

void explore(vector<int> vec[], vector<bool> &vis, int u)
{
    vis[u]=true;
    for (int i=0;i<vec[u].size();i++)
    {
        if (!vis[vec[u][i]]) explore(vec, vis, vec[u][i]);
    }
}

int dfs(vector<int> vec[], vector<bool> &vis, int n)
{
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            explore(vec, vis, i);
            ans++;
        }
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i;
	cin>>n>>m;
	vector<int> vec[n+1];
	for (i=0;i<m;i++)
	{
	    int i1, i2;
	    cin>>i1>>i2;
	    vec[i1].push_back(i2);
	    vec[i2].push_back(i1);
	}
	vector<bool> vis(n+1, false);
	cout<<dfs(vec, vis, n);
	return 0;
}
