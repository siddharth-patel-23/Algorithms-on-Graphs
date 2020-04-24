#include <bits/stdc++.h>
using namespace std;

struct use
{
    long long int e, w;
    use(int e = 0, int w = 0): e(e), w(w) {}
};

class comp
{
    public:
        long long int operator()(use u1, use u2)
        {
            return u1.w>u2.w;
        } 
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long int n, m, i;
	cin>>n>>m;
	vector<use> vec[n+1];
	for (i=0;i<m;i++)
	{
	    int u, v, w;
	    cin>>u>>v>>w;
	    use e;
	    e.e=v;
	    e.w=w;
	    vec[u].push_back(e);
	}
	long long int s, d;
	cin>>s>>d;
	vector<use> dist(n+1);
	for (i=0;i<=n;i++)
	{
	    dist[i].e=i;
	    dist[i].w=INT_MAX;
	}
	dist[s].w=0;
	vector<bool> vis(n+1, false);
	priority_queue<use, vector<use>, comp> pq;
	
	pq.push(use(s, 0));
	while(!pq.empty())
	{
	    if (vis[pq.top().e])
	    {
	        pq.pop();
	        continue;
	    }
	    use u=pq.top();
	    pq.pop();
	    vis[u.e]=true;
	    for (i=0;i<vec[u.e].size();i++)
	    {
	        use v=vec[u.e][i];
	        if (dist[v.e].w>dist[u.e].w+v.w)
	        {
	            dist[v.e].w=dist[u.e].w+v.w;
	            pq.push(v);
	        }
	    }
	}
	if (dist[d].w!=INT_MAX)
	cout<<dist[d].w<<"\n";
	else cout<<-1<<"\n";
	return 0;
}
