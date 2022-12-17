#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  N        200002
vector<ll>g[N];
bool vis[N];
void dfs(ll node)
{
    vis[node]=1;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(vis[child]==0)
        {
            dfs(child);
        }
    }

}
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
       g[v].push_back(u);
   }
   dfs(0);
   for(i=0;i<n;i++)
   {
       cout<<i<<"-->";
       for(j=0;j<g[i].size();j++)
       {
           cout<<g[i][j]<<" ";
       }
       cout<<endl;
   }
   for(i=0;i<n;i++)
   {
       if(vis[i]==1)
       {
           cout<<i<<" ";
       }
       else cout<<"*"<<i<<" ";
   }
   cout<<endl;
}
void dfs(int node,int par=-1,int cnt=0)
{
    mx=max(mx,cnt);
    vis[node]=1;
  for(auto child:adj[node])
  {
    if(child==par)continue;

    if(!vis[child])dfs(child,node,cnt+1);


  }
}
