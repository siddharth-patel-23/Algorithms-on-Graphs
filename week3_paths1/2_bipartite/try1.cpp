#include <bits/stdc++.h>
using namespace std;

bool isB(vector<int> vec[], int n)
{
    vector<int> color(n+1, -1);
    color[1]=0;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<vec[u].size();i++)
        {
            int v=vec[u][i];
            if (color[v]==-1)
            {
                q.push(v);
                color[v]=1-color[u];
            }
            else if (color[u]==color[v]) return 0;
        }
    }
    return 1;
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
	    vec[v].push_back(u);
	}
	if (m>0)
	cout<<isB(vec, n);
	else cout<<0;
	return 0;
}
