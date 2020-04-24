#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, i, j;
	double x, y;
	cin>>n;
	vector<int> adj[n];
	vector<vector<double>> graph(n, vector<double> (n));
	vector<double> vx(n), vy(n);
	for (i=0;i<n;i++)
	    cin>>vx[i]>>vy[i];
    
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            graph[i][j]=graph[j][i]=sqrt((vx[i]-vx[j])*(vx[i]-vx[j])+(vy[i]-vy[j])*(vy[i]-vy[j]));
        }
    }
    for (i=0;i<n;i++) graph[i][i]=0;
    vector<bool> vis(n, false);
    vector<double> key(n, INT_MAX);
    key[0]=0;
    for (i=0;i<n-1;i++)
    {
        int u;
        double cmp=INT_MAX;
        for (j=0;j<n;j++)
        {
            if (cmp>key[j] && !vis[j]) u=j, cmp=key[j];
        }
        vis[u]=true;
        for (j=0;j<n;j++)
        {
            if (!vis[j] && key[j]>graph[u][j]) key[j]=graph[u][j];
        }
    }
    double ans=0;
    for (i=0;i<n;i++) ans+=key[i];
    cout<<fixed<<setprecision(9)<<ans<<"\n";
	return 0;
}
