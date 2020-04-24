#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, j;
	cin>>n>>m;
	vector<int> vec[n+1];
	for (i=0;i<m;i++) 
	{
	    int u, v;
	    cin>>u>>v;
	    vec[u].push_back(v);
	}
	vector<bool> vis(n+1, false);
	vector<int> ind(n+1, 0);
	for (i=1;i<=n;i++)
	{
	    for (j=0;j<vec[i].size();j++)
	    {
	        ind[vec[i][j]]++;
	    }
	}
	queue<int> q;
	for (i=1;i<=n;i++)
	{
	    if (ind[i]==0)
	    {
	        q.push(i);
	    }
	}
	while(!q.empty())
	{
	    int u=q.front();
	    cout<<u<<" ";
	    q.pop();
	    for (i=0;i<vec[u].size();i++)
	    {
	        if (--ind[vec[u][i]]==0) q.push(vec[u][i]);
	    }
	}
	
	return 0;
}
