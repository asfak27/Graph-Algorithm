#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  N        200002
vector<ll>g[N];
bool vis[N];
bool stk[N];
ll par[N];
void dfs(ll node)
{
    vis[node]=true;
    stk[node]=true;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(!vis[child])
        {
            par[child]=node;
            dfs(child);
        }
        else if(stk[child])
        {
            ll startnode=node;
            ll endnode=child;
            vector<ll>v;
            v.push_back(startnode);
            while(startnode!=endnode)
            {
                startnode=par[startnode];
                v.push_back(startnode);
            }
            v.push_back(node);
            reverse(v.begin(),v.end());
            cout<<v.size()<<endl;
            for(i=0;i<v.size();i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
            exit(0);
        }
    }
    stk[node]=false;

}

/*bool iscycle(ll node)
{
    vis[node]=1;
    for(ll i=0; i<g[node].size(); i++)
    {
        ll child=g[node][i];
        if(vis[child]==1) return 0;
        else if(vis[child]==0)if(!iscycle(child))return 0;

    }
    vis[node]=2;
    return 1;
}*/
int main()
{
   //freopen("textnew.txt","r",stdin);
   ll n,e,m,i,j;
   cin>>n>>e;
   for(i=0;i<e;i++)
   {
       ll u,v;
       cin>>u>>v;
       g[u].push_back(v);

   }
   for(i=1;i<=n;i++)
   {
       if(!vis[i])
       {
           dfs(i);
       }
   }
   cout<<"IMPOSSIBLE"<<endl;
}
