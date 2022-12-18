//**disjoint set union(dsu)
//*disjoint set union (dsu)it search a node parents and merge two node as a set
#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  mod       1000000007
#define  mx        1002
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll parent[mx];
///initialization & make each element in each parents node
void init()
{
    for(ll i=1; i<=8; i++)
    {
        parent[i]=i;
    }
}
///find parents of a node
ll findparent(ll u)
{
    if(u != parent[u])
        parent[u] = findparent(parent[u]);
    return parent[u];
}
/*
int findparent(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=findparent(parent[x]);
}
*/
///add/merg two element in one set
void Union(ll u,ll v)
{
    ll p=findparent(u);//find parents of u
    ll q=findparent(v);//find parents of v;
    if(p!=q)parent[q]=p;
}
///if union not work
/*void unionset(ll x,ll y)
{
    if(x>y)
    {
        swap(x,y);
    }
    parent[y]=x;
}*/

ll unionset(ll a , ll b){

	a = findpar(a);
	b = findpar(b);
	if(rankpar[a] < rankpar[b]) swap(a , b);
	par[b] = a;
	rankpar[a]+=rankpar[b];

	return rankpar[a];
}

///cheake if two element in one set
bool isSameSet(ll u,ll v)
{
    ll p=findparent(u);
    ll q=findparent(v);
    if(p==q)return true;
    else return false;
}
int main()
{
    ll i,j,k;
    init();

    Union(1, 2);
    Union(2, 3);
    Union(3, 4);
    Union(4, 5);
    Union(5, 6);
    Union(6, 7);
    Union(7, 8);
    cout<<findparent(1)<<" "<<findparent(3)<<endl;
    if (isSameSet(4, 7))
    {
        cout << "They are friends!" << endl;
    }
    else cout << "They are not friends!" << endl;

    return 0;
}
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define endl       '\n'
#define  inf       1000000007
#define  N         2000005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll par[N];
ll rankp[N];
void init()
{
    for(ll i=0; i<=N; i++)
    {
        par[i]=i;
        rankp[i]=1;
    }
}
ll findparent(ll u)
{
    if(u!=par[u])par[u]=findparent(par[u]);
    return par[u];
}
void Union(ll u,ll v)
{
    ll p=findparent(u);
    ll q=findparent(v);
    if(p!=q)
    {
        if(rankp[p]<rankp[q])swap(p,q);
        par[q]=p;
        rankp[p]+=rankp[q];
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    vector<ll>p;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,z,x,r,y,q,k;
    cin>>n>>m;
    init();
    for(i=0; i<m; i++)
    {
        cin>>x;
        if(x==0)continue;
        ll u,v;
        cin>>u;
        for(j=1; j<x; j++)
        {
            cin>>v;
            Union(u,v);
            u=v;
        }
    }
    for(i=1; i<=n; i++)
    {
        cout<<rankp[findparent(i)]<<" ";
    }
}
int main()
{
    fast;
    int T=1;
    // cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
