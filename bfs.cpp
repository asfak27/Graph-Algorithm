#include<bits/stdc++.h>//it search levelewize unweahted graph
using namespace std;
#define ll long long

vector<ll>g[100];
bool vis[100];  //visited node
ll dis[100];    //distance node

void bfs(ll x)//x=source node
{
    queue<ll>q;
    vis[x]=1;
    dis[x]=0;
    q.push(x);
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(ll i=0;i<g[node].size();i++)
        {
            ll next=g[node][i];//cheak neighbor node
            if(vis[next]==0)
            {
                vis[next]=1;//visited
                dis[next]=dis[node]+1; //update
                q.push(next); //push queue to cheak another node
            }
        }

    }
}
int main()
{
   //freopen("textnew.txt","r",stdin);
   ll n,e,i,j;
   cin>>n>>e;
   for(i=1;i<=e;i++)
   {
       ll u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   cout<<"Enter Source node:";
   ll source;
   cin>>source;
   bfs(source);

   //cheake distance from source node to another node

   for(i=1;i<=n;i++)
   {
       cout<<"Distance of source node to "<<i<<"th node is ==> "<<dis[i]<<endl;
   }

}
/*
 7 9
 1 2
 1 3
 1 7
 2 3
 3 7
 2 4
 4 5
 3 6
 5 6
 */


/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define white 1
#define gray 2
#define black 3

ll adj[100][100];
ll color[100];
ll parent[100];
ll dis[100];
ll node,edge,n,m,i,j;

void bfs(ll startnode)
{
    for(i=0;i<node;i++)
    {
        color[i]=white;
        dis[i]=-1e9;
        parent[i]=-1;
    }
    dis[startnode]=0;
    parent[startnode]=-1;
    queue<ll>q;
    q.push(startnode);
    while(!q.empty())
    {
        ll x=q.front();
        q.pop();
        color[x]=gray;
        cout<<x<<" ";
        for(i=0;i<node;i++)
        {
            if(adj[x][i]==1)
            {
                if(color[i]==white)
                {
                    //x er negibour i
                    //x no node ta hoccea i no node er parent
                    dis[i]=dis[x]+1;
                    parent[i]=x;
                    q.push(i);
                }
            }
        }
        color[x]=black;
    }
}
int main()
{
   //freopen("textnew.txt","r",stdin);

   cin>>node>>edge;
   for(i=0;i<edge;i++)
   {
       cin>>n>>m;
       adj[n][m]=1;
       adj[m][n]=1;
   }
   cout<<endl;
   bfs((ll)0);
   cout<<endl<<parent[7]<<endl;

   /*for(i=0;i<node;i++)
   {
       for(j=0;j<node;j++)
       {
           cout<<adj[i][j]<<" ";
       }
       cout<<endl;
   }*/

/*
 8 7
 0 1
 0 2
 1 3
 2 4
 2 5
 3 6
 3 7
 */
