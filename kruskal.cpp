///its find minimum spanning tree and find the shortest way to visit all node
///edge gula increasing order a sagano thakbe
#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  mod       1000000007
#define  mx        200002
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
struct edgestruct{
     ll u;
     ll v;
     ll w;
};

bool operator<(edgestruct lhs ,edgestruct rhs)
{
    return lhs.w < rhs.w;
}

ll parent[mx];
ll rankparent[mx];

vector<edgestruct>ev;//edgevector


///initialization set & make each element in each parents node
void init(ll n)
{
    for(ll i=0; i<=n; i++)
    {
        parent[i]=i;
        rankparent[i]=0;
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
void unionset(ll u,ll v)
{
    ll p=findparent(u);//find parents of u
    ll q=findparent(v);//find parents of v;
    if(p==q)return;
    ///je node er child besi oi node ta new node er parent hobe
    ///rankparent means the number of child in this node
    if(rankparent[p]<rankparent[q])
    {
        parent[p]=q;
    }
    else if(rankparent[p]>rankparent[q])
    {
        parent[q]=p;
    }
    else{

         parent[q]=p;
         rankparent[p]++;
    }
}

//ll unionset(ll a , ll b){
//
//	a = findpar(a);
//	b = findpar(b);
//	if(rankpar[a] < rankpar[b]) swap(a , b);
//	par[b] = a;
//	rankpar[a]+=rankpar[b];
//
//	return rankpar[a];
//}
/*
///if unionset not work
void unionset(ll x,ll y)
{
    if(x>y)
    {
        swap(x,y);
    }
    parent[y]=x;
}
*/
ll kruskal(ll n)
{
    init(n);
    sort(ev.begin(),ev.end());
    ll len=ev.size();
    ll sum=0;
    for(ll i=0;i<len;i++)
    {
        if(findparent(ev[i].u)!=findparent(ev[i].v))
        {
           //cout<<parent[ev[i].u]<<" "<<parent[ev[i].v]<<endl;
            unionset(parent[ev[i].u],parent[ev[i].v]);
            sum+=ev[i].w;
        }
    }
    return sum;

}
int main()
{
    ll i,j,k;

    ll n,e;
    cin>>n>>e;
   // memset(&ev, 0, sizeof(ev));
    for(i=0;i<e;i++)
    {
        edgestruct eg;
        cin>>eg.u>>eg.v>>eg.w;
        ev.push_back(eg);
    }
    ll mincost=kruskal(n);

    cout<<mincost<<endl;



    return 0;
}
