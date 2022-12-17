///it is shortest path finding algorithm and edge cost is positive or negative.
/// it use to find negative cycle and it is single source graph
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000
#define mx 100005
struct node
{
    ll u;
    ll v;
    ll cost;

};
vector<node>g;
ll dis[mx];
ll par[mx];

void bellman_ford(ll n)
{
    ll x;//p=the last cycle node
    for(ll i=1; i<=n; i++)
    {
        x=-1;
        for(ll j=0;j<g.size();j++)
        {
            ll curr=g[j].u;
            ll nxt=g[j].v;
            ll cst=g[j].cost;
            if(dis[curr]+cst<dis[nxt])
            {
                dis[nxt]=dis[curr]+cst;
                par[nxt]=curr;
                x=nxt;///the last element of the cycle
            }
        }
    }
    if(x == -1)
        cout << "NO" << endl;

    else
    {
        vector<ll>v;
        ///trackback to find the first element of cycle
        for(ll i = 1; i <= n; ++i)
        {
            x = par[x];
        }
        v.push_back(x);
        ll k=par[x];
        while(k!=x)
        {
            v.push_back(k);
            k=par[k];
        }
        v.push_back(x);
        cout<<"YES"<<endl;
        reverse(v.begin(),v.end());
        for(ll i=0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    //freopen("textnew.txt","r",stdin);

    ll n,e,m,i,j;
    cin>>n>>e;
    for(i=1; i<=e; i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        node p;
        p.u=u;
        p.v=v;
        p.cost=c;
        g.push_back(p);
    }
    bellman_ford(n);
}

