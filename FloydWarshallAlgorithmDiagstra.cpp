///Floyd Warshall Algorithm (All pairs shortest path)it works negative value
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> g;
ll INF = 1e15;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll i,j,k,q;
    cin >> n >> m >> q;
    g.resize(n+1);
    for(i=0; i<=n; i++)
    {
        g[i].resize(n+1);
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            g[i][j]=INF;
            if(i==j)g[i][j]=0;
        }
    }
    for(i=0; i<m; i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        g[u][v]=c;
        g[v][u]=c;
    }

    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(i=0; i<q; ++i)
    {
        ll u, v;
        cin >> u >> v;
        if(g[u][v] == INF)
            g[u][v] = -1;
        cout << g[u][v] << endl;
    }
    return 0;
}
