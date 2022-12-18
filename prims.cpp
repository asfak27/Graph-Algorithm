///its find minimum spanning tree and find the shortest way to visit all node
#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  mod       1000000007
#define  mx        1002
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
void initializeset(ll n)
{
    for(ll i=0; i<=n; i++)
    {
        parent[i]=i;
        rankparent[i]=0;
    }
}
///find parents of a node
int findparent(ll u)
{
    if(u==parent[u])return u;
    else parent[u]=findparent(parent[u]); //set as dp method=path compression
}
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

ll kruskal(ll n)
{
    initializeset(n);
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

    ll node,edge;
    cin>>node>>edge;

    for(i=0;i<edge;i++)
    {
        edgestruct e;
        cin>>e.u>>e.v>>e.w;
        ev.push_back(e);
    }
    ll mincost=kruskal(node);

    cout<<mincost<<endl;



    return 0;
}

