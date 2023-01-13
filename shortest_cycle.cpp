///                            Israt Jahan Reshma
///                              ID: 18ICTCSE041
///                                  BSMRSTU

///...........................****************************............................///


#include<bits/stdc++.h>
#include<stdio.h>
#include<unordered_set>

using namespace std;


//.....................Keywords..................>
#define ll              long long
#define lli             long long int
#define ull             unsigned long long
#define ld              long double
#define vi              vector<int>
#define vll             vector<ll>
#define pii             pair<int,int>
#define vii             vector<pii>
#define pii             pair<int,int>
#define tiii            tuple<int,int,int>
#define pb              push_back
#define F               first
#define S               second
//#define mp              make_pair
#define I               insert
#define endl            "\n"
#define pob             pop_back
#define inf             1e9+9
#define setpoint(x)     setprecision(x)<<fixed

const int         N   = (int) 2e3 + 5;//100000
const int         MxN = (int) 1e6 + 5;
const int         MOD = (int) 1e9 + 7;
const int         INF = (int) 1e9 + 7;
const double      EPS = (double) 1e-9;
const long double PI  = 3.14159265358979;
const lli         M   =  1e6+2;  //998244353;

///.....................function..................>

#define fastio()        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define loop(a,b)       for(ll i=a;i<b;i++)
#define loopr(a,b)      for(ll i=a-1;i>=b;i--)
#define Ssort(a)         sort(a.begin(),a.end())
//sort(a,a+3,greater<ll>());
#define rsort(v)        sort(v.rbegin(),v.rend())
#define gcd(a,b)        __gcd(a,b)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define rev_sort(a)     sort(a.begin(),a.end(),greater<int>())
//#define reverse(a)      reverse(a.begin(),a.end())
#define sum_arr(a,n,s)  accumulate(a,a+n,s)
#define bin_one(n)      __builtin_popcount(n)
#define str(a)          a.begin(),a.end()
#define mem(a,b)        memset(a, b, sizeof(a) )
#define max_ele(a,n)    *max_element(a,a+n)
#define min_ele(a,n)    *min_element(a,a+n)
#define print(a,n)      for(ll i=0;i<n;i++)cout<<a<<" ";
#define pll             pair <ll, ll>
#define yes             cout<<"YES\n"
#define no              cout<<"NO\n"
#define read(x)         int x; cin >> x
const ll md=998244353;
ll cs;
vector<ll>adj[N];
ll vis[N];
ll live[105];
ll n,m,k;
ll cnt;
void dfs(ll node)
{
    vis[node]=1;
    if(live[node])cnt++;
    if(cnt>=k)return;
    for(auto v: adj[node])
    {
        if(!vis[v])dfs(v);
    }
}
void refresh(ll n)
{
    for(int i=0;i<=n+1;i++)adj[i].clear();
    for(int i=0;i<=k+1;i++)live[i]=0;
}
void solve()
{
    ll ans=0,i,j;
    cin>>k>>n>>m;
    refresh(n);
    for(i=1;i<=k;i++)
    {
        ll x;
        cin>>x;
        live[x]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        dfs(i);

        if(cnt>=k)ans++;
        cnt=0;

    }
    cout<<"Case "<<++cs<<": "<<ans<<endl;

}

int main()
{
   // fastio();

    ll tc; tc=1;
    cin>>tc;
    //sieve();

    while(tc--)solve();


}
