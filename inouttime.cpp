#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define  mod       1000000007
#define  sz         200005
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[sz];
ll in[sz];
ll out[sz];
ll timer=0;
ll lvl[sz];
void dfs(ll node,ll par)
{
    in[node]=++timer;
    for(ll i=0; i<g[node].size(); i++)
    {
        ll child=g[node][i];
        if(child!=par)
        {
            lvl[child]=lvl[node]+1;
            dfs(child,node);
        }
    }
    out[node]=++timer;
}
struct BIT
{
    ll N;
    vector<ll> bit;
    void init(ll n)
    {
        N = n;
        bit.assign(n + 1, 0);
    }
    void update(ll idx, ll val)
    {
        while(idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    ll query(ll idx)
    {
        ll ans = 0;
        while(idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
    ll rsum(ll l,ll r)
    {
        return query(r)-query(l - 1);
    }
};
void solve()
{

    ll n,i,j,m;
    cin>>n>>m;
    ll a[n+1];
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(i=1; i<n; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    lvl[0]=0;
    dfs(1,0);

    BIT q;
    q.init(sz+1);

    while(m--)
    {
        ll typ;
        cin>>typ;
        if (typ==1)
        {
            ll x, val;
            cin>>x>>val;
            if (lvl[x]&1)
            {
                q.update(in[x], -val);
                q.update(out[x], val);
            }
            else
            {
                q.update(in[x], val);
                q.update(out[x], -val);
            }
        }
        else
        {
            ll x;
            cin>>x;
            ll ans=0;
            if (lvl[x]&1)
            {
                ans=a[x]-q.query(in[x]);
            }
            else
            {
                ans=a[x]+q.query(in[x]);
            }
            cout<<ans<<endl;
        }
    }
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
