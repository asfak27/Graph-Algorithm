//it is shortest path and longest path finding algo and edge cost is positive and all negative(nlogn+m) for negative path use Bellman Ford Algorithm
//single source graph
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000000
#define mx 100009

vector<pair<ll, ll>>g[mx];
bool vis[mx];
ll dis[mx];///distance
void reset()
{
    for(ll i=0; i<mx; i++)
    {
        g[i].clear();
        vis[i]=0;
        dis[i]=inf;
    }
}
void digkstra(ll s,ll n)//s=source;
{
    for(ll i=0; i<n; i++)
    {
        dis[i]=inf;
    }
    dis[s]=0;
    priority_queue <pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >q;
    q.push({0,s});//push cost,source node//first value cost second value node number

    while(!q.empty())
    {
        ll currnode=q.top().second;
        ll currdis=q.top().first;
        q.pop();

        if(dis[currnode]<currdis)continue;//importent
        ///cheake distance of all adjacent node of current node
        for(ll i=0; i<g[currnode].size(); i++)
        {
            ll nxtnode=g[currnode][i].first;
            ll nxtdis=g[currnode][i].second;

            if(currdis+nxtdis < dis[nxtnode])  ///if current distance is less previous distance(dis[nxtnode])
            {
                dis[nxtnode]=currdis+nxtdis;
                q.push({dis[nxtnode],nxtnode});
            }

        }

    }

}
int main()
{
    //freopen("textnew.txt","r",stdin);
    // reset();

    ll node,edge,n,m,i,j,source;
    cin>>node>>edge;
    for(i=1; i<=edge; i++)
    {
        ll u,v,cost;
        cin>>u>>v>>cost;
        g[u].push_back({v,cost});
        //g[v].push_back({u,cost});
    }
    //cout<<node<<endl;
    digkstra(1,node+1);

    for(i=1; i<=node; i++)
    {
        if(dis[i]==inf)
        {
            cout<<30000<<" ";
        }
        else cout<<dis[i]<<" ";
    }
    cout<<endl;

}
/*
///longest path

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000000000000
#define mx 100009

vector<pair<ll,ll>>g[mx];
bool vis[mx];
ll dis[mx];
ll par[mx];
void digkstra(ll s,ll n)
{
    for(ll i=1; i<=n; i++)
    {
        par[i]=-1;
    }
    dis[s]=0;
    priority_queue <pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> >q;
    q.push({0,s});

    while(!q.empty())
    {
        ll currnode=q.top().second;
        ll currdis=q.top().first;
        q.pop();

        if(dis[currnode]<currdis)continue;
        for(ll i=0; i<g[currnode].size(); i++)
        {
            ll nxtnode=g[currnode][i].first;
            ll nxtdis=g[currnode][i].second;
            if(currdis+nxtdis < dis[nxtnode])
            {
                par[nxtnode]=currnode;//shortest parth
                dis[nxtnode]=currdis+nxtdis;
                q.push({dis[nxtnode],nxtnode});
            }

        }

    }

}
int main()
{
    //freopen("textnew.txt","r",stdin);

    ll node,edge,n,m,i,j,source;
    cin>>node>>edge;
    for(i=1; i<=edge; i++)
    {
        ll u,v,cost;
        cin>>u>>v;
        cost=-1;
        g[u].push_back({v,cost});
       // g[v].push_back({u,cost});
    }
    digkstra(1,node+1);

    if(dis[node]==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(i=2;i<=node;i++)
        {
            cout<<dis[i]<<" ";
        }
        cout<<endl;
        ll x=node;
        vector<ll>v;
        v.push_back(x);
        while(x!=-1)
        {
            x =par[x];
            v.push_back(x);
        }
        cout<<v.size()-1<<endl;
        reverse(v.begin(),v.end());
        for(i=1; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

}


*/
/*
//it is shortest path finding algo and edge cost is positive
//directed graph
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000000
#define mx 105
struct node
{
    ll val;
    ll cost;
};
vector<node>g[mx];
bool vis[mx];  //visited node
ll dis[mx];    //distance node
void reset()
{
    for(ll i=0; i<mx; i++)
    {
        g[i].clear();
        vis[i]=0;
        dis[i]=inf;
    }
}
class cmp
{
public:
    bool operator()(node &A,node &B)
    {
        if(A.cost>B.cost)return true;
        else return false;
    }

};


void digkstra(ll source)//x=source node
{
    priority_queue<node,vector<node>,cmp>q;
    q.push({source,0});

    while(!q.empty())
    {
        node curr=q.top();
        q.pop();

        ll val=curr.val;
        ll cost=curr.cost;

        if(vis[val]==0)// cheake nagibhor node if it visited or not
        {
            dis[val]=cost;//final cost
            vis[val]=1;

            for(ll i=0; i<g[val].size(); i++)
            {
                ll nxt=g[val][i].val;
                ll nxtcost=g[val][i].cost;
                if(vis[nxt]==0)
                {
                    q.push({nxt,cost+nxtcost});///push current node cost+next node cost
                }
            }
        }

    }


}
int main()
{
    //freopen("textnew.txt","r",stdin);
    reset();

    ll node,edge,n,m,i,j;
    cin>>node>>edge;
    for(i=1; i<=edge; i++)
    {
        ll u,v,cost;
        cin>>u>>v>>cost;
        g[u].push_back({v,cost});//directed graph
    }
    cout<<"Enter Source Node : ";
    ll source;
    cin>>source;
    digkstra(source);
    cout<<"Shortest distance Source Note to all node :"<<endl;
    for(i=1; i<=node; i++)
    {
        cout<<"Node "<<i<<"to source node is "<<dis[i]<<endl;
    }

}
*/
