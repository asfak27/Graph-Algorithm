#include<bits/stdc++.h>
using namespace std;

vector < int > graph[200005];
bool visited[200005];

vector < int > res;

void dfs(int source)
{

    visited[source] = 1;
    for (int i = 0; i < graph[source].size(); i++)
    {
        int next = graph[source][i];
        if (visited[next] == 0)
            dfs(next);
    }
    // all children explored
    res.push_back(source); // newly included
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);//because directed graph
    }
    for (int i = 1; i <= nodes; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    reverse(res.begin(), res.end());
    if(res.size()!=nodes)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

   // cout << "Topological order: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}
// ans->3 1 2 5 4
/*
5 4
3 2
1 2
2 4
2 5
*/
//it occers directed graph
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define  N        200002
#define  mod       1000000007
vector<ll>g[N],backedge[N];
ll indegree[N];
ll dp[N];
///khan algo
ll top_sort(ll n)
{
    ll i;
    queue<ll>q;
    for(i=0;i<=n;i++)
    {
        if(indegree[i]==0)q.push(i);
    }
    dp[1]=1;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();

        for(i=0;i<g[node].size();i++)
        {
            ll child=g[node][i];
            indegree[child]--;
            if(indegree[child]==0)q.push(child);
        }

        for(i=0;i<backedge[node].size();i++)
        {
            ll child=backedge[node][i];
            dp[node]=(dp[node]+dp[child])%mod;
        }
    }
    return dp[n];

}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll n,e,m,i,j;
    cin>>n>>e;
    for(i=0; i<e; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        backedge[v].push_back(u);
        indegree[v]++;
    }
    ll ans=top_sort(n);
    cout<<ans<<endl;

}
