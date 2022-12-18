#include<bits/stdc++.h>
using namespace std;
#define ll int long long
#define white 0
#define gray 1
#define black 2
vector < ll> g[200005];
ll vis[200005];
bool cycle=false;
vector <ll>ans;

void dfs(ll node)
{
    vis[node]=gray;
    sort(g[node].begin(),g[node].end());
    for (ll i =g[node].size()-1; i>=0; i--)
    {
        ll child=g[node][i];
        if(vis[child]==white)
        {
            dfs(child);
        }
        else if(vis[child]==gray)
        {
            cycle=true;
            return;
        }
    }
    vis[node]=black;
    ans.push_back(node);
}

int main()
{
    ll n,e,i,j,k;
    cin>>n>>e;
    for (i=0; i<e; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for(i=n; i>=1; i--)
    {
        if(vis[i]==white)
        {
            dfs(i);
        }
    }
    if(cycle)
    {
        cout<<"Sandro fails."<<endl;
        return 0;
    }
    reverse(ans.begin(),ans.end());
    for(i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
