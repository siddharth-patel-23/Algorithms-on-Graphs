#include <bits/stdc++.h>
using namespace std;

int explore(vector<int> vec[], int u, vector<bool> &vis, int v)
{
    // cout<<u<<"\n";
    if (u==v) return 1;
    vis[u]=true;
    for (int i=0;i<vec[u].size();i++)
    {
        if (!vis[vec[u][i]])
        if (explore(vec, vec[u][i], vis, v)==1)
        return 1;
    }
    return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, j, u, v;
	cin>>n>>m;
	
	vector<int> vec[n+1];
	for (i=0;i<m;i++)
	{
	    int ip1, ip2;
	    cin>>ip1>>ip2;
	    vec[ip1].push_back(ip2);
	    vec[ip2].push_back(ip1);
	}
	cin>>u>>v;
// 	cout<<u<<" "<<v<<"\n";
	vector<bool> vis(n+1, false);
	if (explore(vec, u, vis, v)==1) cout<<"1";
	else cout<<"0";
	
	return 0;
}
