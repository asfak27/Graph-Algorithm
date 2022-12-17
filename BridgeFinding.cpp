#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define  mod       1000000007
#define  N        200002
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

vector<ll>g[N];
ll vis[N],low[N],in[N];
ll timer,cnt;
void dfs(ll node,ll par)
{
    vis[node]=1;
    low[node]=timer;
    in[node]=timer;
    timer++;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(child==par)continue;
        if(vis[child]==1)
        {
            low[node]=min(low[node],low[child]);
        }
        else{

            dfs(child,node);

            if(low[child]>in[node])
            {
                cnt++;
                cout<<node<<" ans "<<child<<" is a brige"<<endl;
            }
            low[node]=min(low[node],low[child]);
        }
    }

}
void solve()
{
    //vector<ll>v,v1;
    map<ll,ll>mp;
    ll n,m,j,i,k,len,z,p,x,y;
    ll e;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<endl;
    dfs(1,-1);
    cout<<cnt<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
