#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define  no               cout<<"No"<<endl
#define  yes              cout<<"Yes"<<endl
#define  N    200006
#define  mod       1000000007
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
ll lvl[N], sz[N];
vector<ll>ans;
void dfs(ll u,ll par)
{
    sz[u]=1;
    lvl[u]=lvl[par]+1;
    for(ll i=0;i<g[u].size();i++)
    {
        ll v=g[u][i];
        if(v==par)continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    set<ll>st;
    map<ll,ll>mp;
    ll n,e,i,j,m,x,y,z,r,k;
    cin>>n;
    for(i=0; i<n-1; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(i=1;i<=n;i++)
    {
        cout<<lvl[i]<<" ";
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<sz[i]<<" ";
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
