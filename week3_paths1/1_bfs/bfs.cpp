#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, i, u, v;
	cin>>n>>m;
	
	vector<int> vec[n+1];
	for (i=0;i<m;i++)
	{
	    int i1, i2;
	    cin>>i1>>i2;
	    vec[i1].push_back(i2);
	    vec[i2].push_back(i1);
	}
	cin>>u>>v;
	vector<int> dist(n+1, INT_MAX);
	dist[u]=0;
	queue<int> q;
	q.push(u);
	bool f=false;
	while(!q.empty())
	{
	    int u1=q.front();
	    q.pop();
	    for (i=0;i<vec[u1].size();i++)
	    {
	        
	        if (dist[vec[u1][i]]==INT_MAX)
	        {
	            q.push(vec[u1][i]);
	            dist[vec[u1][i]]=dist[u1]+1;
	        }
	        if (vec[u1][i]==v)
	        {
	            f=true;
	            break;
	        }
	    }
	    if (f) break;
	}
	if (dist[v]!=INT_MAX) cout<<dist[v];
	else cout<<-1;
	return 0;
}
