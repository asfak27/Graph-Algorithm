#include <bits/stdc++.h>
using namespace std;
#define MP ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Forn(i,a,n) for (ll i = a; i < n; i++)
#define Fors(i,s) for (ll i = 0; i < s.size(); i++)
#define all(v) v.begin(), v.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * (b / __gcd(a, b)))
#define vprint(v) {Fors(i,v)cout<<v[i]<<" ";cout<<"\n";}
#define arprint(a,n) {Forn(i,0,n)cout<<a[i]<<" ";cout<<"\n";}
#define vpprint(vp) {Fors(i,vp) {cout << vp[i].ff << " " << vp[i].ss << endl;}}
#define mpprint(mp) for (auto it : mp) {cout <<it.ff << " " << it.ss << endl;}
#define gt greater<ll>()
#define ff first
#define ss second
#define pb push_back
#define vi vector<ll>
#define mod 1000000007
#define sp(n) fixed << setprecision(n)
#define Erase(s) s.erase(unique(s.begin(), s.end()), s.end())
#define ll long long
#define yes cout << "YES" << endl
#define no  cout << "NO" << endl
ll Ceil(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
const ll Mx = 1e5+5;
//%%%%%%%%%%%p%%%a%%%r%%%v%%%e%%%z%%%%%%%%%%//
ll n, m, sv, ev, vis[Mx], par[Mx];
vi ar[Mx];
bool dfs(ll node, ll p) {
    vis[node] = 1;
    par[node] = p;
    for (auto child : ar[node]) {
        if (child == p) continue;
        if (vis[child]) {
            sv = child, ev = node;
            return true;
        }
        if (!vis[child]) {
            ll f = dfs(child,node);
            if (f) return true;
        }
    }
    return false;
}
bool vis_all() {
    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i,-1)) return true;
        }
    }
    return false;
}
void solve()
{
    vi ans;
    map <ll, ll> mp, pp;
    string s, t;
    //ll n, m, sm = 0, ans = 0, c = 0, mx = 0;
    cin >> n >> m;
    while(m--) {
        ll x, y;
        cin >> x >> y;
        ar[x].pb(y);
        ar[y].pb(x);
    }
    if (!vis_all()) {
        cout << "IMPOSSIBLE" << endl; return;
    }
    ll f = ev;
    ans.pb(ev);
    while(ev != sv)
    {
        ans.pb(par[ev]);
        ev = par[ev];
    }
    ans.pb(f);
    cout << ans.size() << endl;
    vprint(ans);
}
int main()
{
    //freopen("input.txt","r",stdin);
    MP;
    int T = 1;
    //cin >> T; for (int i = 1; i <= T; i++)
    solve();

    cerr<<endl<<(float)clock()/(float)CLOCKS_PER_SEC<<" sec"<<endl;
    return 0;
}

///find maximum cycle
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll       long long int
#define mod      1000000007
#define N        200005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
ll vis[N];
ll par[N];
ll cnt,k;
vector<ll>vv;
bool f=false;
void is_valid_cycle(ll u,ll v)
{
    vector<ll>ans;
    while(u!=v)
    {
        ans.push_back(u);
        u=par[u];
    }
    ans.push_back(u);
    if(ans.size()>k)
    {
        f=true;
        for(ll i=0; i<ans.size(); i++)
        {
            vv.push_back(ans[i]);
        }
    }
}
void dfs(ll node,ll p)
{
    if(f)return;
    vis[node]=1;
    par[node]=p;
    for(ll i=0; i<g[node].size(); i++)
    {
        ll child=g[node][i];
        if(child==p)continue;

        if(vis[child] && !f)
        {
            is_valid_cycle(node,child);
        }
        if(!vis[child])
        {
            dfs(child,node);
        }
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    map<ll,ll>mp;
    ll e,i,j,l,m,x,y,z,r,n;
    string s,t;
    cin>>n>>m>>k;
    for(i=0; i<m; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    cout<<vv.size()<<endl;
    for(j=0; j<vv.size(); j++)
    {
        cout<<vv[j]<<" ";
    }
    cout<<endl;

}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}
