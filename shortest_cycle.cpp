#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll          long long
//#define  mod      1000000007
#define  N         10005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll cs;
vector<ll>g[N+1];
ll shortest_cycle(ll n)
{
    ll ans = INT_MAX;
    for (ll i = 0; i <n; i++)
    {
        vector<ll> dist(n, (ll)(1e9));
        vector<ll> par(n, -1);
        dist[i] = 0;
        queue<ll> q;
        q.push(i);
        while (!q.empty())
        {
            ll x = q.front();
            q.pop();
            for (ll child : g[x])
            {
                // If it is not visited yet
                if (dist[child] == (ll)(1e9))
                {
                    dist[child] = 1 + dist[x];
                    par[child] = x;
                    q.push(child);
                }
                // If it is already visited
                else if (par[x] != child and par[child] != x)
                    ans = min(ans, dist[x] + dist[child] + 1);
            }
        }
    }
    return ans;
}
ll clr(ll n)
{
    for(ll i=0;i<=n;i++)
    {
        g[i].clear();
    }
}
void solve()
{
    ll i,j,k,n,m;
    cin>>n>>m;
    clr(n);
    for(i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans=shortest_cycle(n);
    cout<<"Case "<<++cs<<": ";
   // cout<<ans<<endl;
    if(ans==INT_MAX)
    {
        cout<<"impossible"<<endl;
    }
    else cout<<ans<<endl;
}
int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}

