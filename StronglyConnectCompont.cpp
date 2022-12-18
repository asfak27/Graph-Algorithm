/// Kosaraju's Algorithm
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long int
#define mod      998244353
#define N        300005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
vector<ll>rg[N];///reverse graph
ll vis[N];
vector<ll>v;
vector<ll>ans;

void dfs1(ll node)
{
    vis[node]=1;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(vis[child]==0)dfs1(child);
    }
    v.push_back(node);
}
void dfs2(ll node)
{
    vis[node]=1;
    for(ll i=0;i<rg[node].size();i++)
    {
        ll child=rg[node][i];
        if(vis[child]==0)dfs2(child);
    }
    ans.push_back(node);
}

void solve()
{
    //freopen("textnew.txt","r",stdin);
    set<ll>s;
    map<ll,ll>mp;
    map<ll,ll>pp;
    ll n,e,i,j,l,m,x,y,z,r,k;
    cin>>n>>m;

    for(i=1; i<=m; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)dfs1(i);
    }
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(i=v.size()-1;i>=0;i--)
    {
        if(vis[v[i]]==0)
        {
            ans.clear();
            dfs2(v[i]);
            cout<<v[i]<<"->";
            for(j=0;j<ans.size();j++)
            {
                cout<<ans[j]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<endl;



}
int main()
{
    fast;
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}



