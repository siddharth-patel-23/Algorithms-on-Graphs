#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, j, k;
	cin>>n>>m;
	vector<int> adj[n+1];
	vector<int> cost[n+1];
	for (i=0;i<m;i++)
	{
	    int u, v, w;
	    cin>>u>>v>>w;
	    adj[u].push_back(v);
	    cost[u].push_back(w);
	}
	vector<long> dist(n+1, INT_MAX);
	dist[1]=0;
	for (i=0;i<n;i++)
	{
	    bool f=false;
	    for (j=1;j<=n;j++)
	    {
	       // if (dist[j]==INT_MAX) continue;
	        for (k=0;k<adj[j].size();k++)
	        {
	            int v=adj[j][k];
	            int w=cost[j][k];
	            if (dist[v]>dist[j]+w)
	            {
	                dist[v]=dist[j]+w;
	                f=true;
	            }
	        }
	    }
	    if (i!=n-1) continue;
	    if (f) 
	    cout<<1;
	    else cout<<0;
	}
	return 0;
}
