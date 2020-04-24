#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int n, m, i, j, k;
	cin>>n>>m;
	vector<long long> adj[n+1], cost[n+1];
	for (i=0;i<m;i++)
	{
	    int u, v, w;
	    cin>>u>>v>>w;
	    adj[u].push_back(v);
	    cost[u].push_back(w);
	}
	int s;
	cin>>s;
	vector<long long> dist(n+1, INT_MAX);
	dist[s]=0;
	for (i=0;i<2*n;i++)
	{
	    for (j=1;j<=n;j++)
	    {
	        for (k=0;k<adj[j].size();k++)
	        {
	            long long int v=adj[j][k];
	            long long int w=cost[j][k];
	            if (dist[v]>dist[j]+w)
	            {
	                dist[v]=dist[j]+w;
	                if (i>=n-1)
	                dist[v]=INT_MIN;
	            }
	        }
	    }
	}
	for (i=1;i<=n;i++)
	{
	    if (dist[i]==INT_MAX) cout<<"*\n";
	    else if (dist[i]==INT_MIN) cout<<"-\n";
	    else cout<<dist[i]<<"\n";
	}
	return 0;
}
