//it occers directed graph
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define  N        200002
vector<ll>g[N];
vector<ll>ans;
bool vis[N];
map<ll,ll>mp;
void kahn(ll n)
{
    priority_queue<ll,vector<ll>,greater<ll>>q;//lexographacally smollest
    for(ll i=1; i<=n; i++)
    {
        if(mp[i]==0)q.push(i);
    }
    while(!q.empty())
    {
        ll curr=q.top();
        ans.push_back(curr);
        q.pop();

        for(ll i=0; i<g[curr].size(); i++)
        {
            ll k=g[curr][i];
            mp[k]--;
            if(mp[k]==0)q.push(k);
        }
    }
}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll n,e,m,i,j;
    cin>>n>>e;
    for(i=0; i<e; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        mp[v]++;
    }
    kahn(n);
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

//it occers directed graph
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define  N        200002
#define  mod       1000000007
vector<ll>g[N],backedge[N];
ll indegree[N];
ll dp[N];
///khan algo
ll top_sort(ll n)
{
    ll i;
    queue<ll>q;
    for(i=0;i<=n;i++)
    {
        if(indegree[i]==0)q.push(i);
    }
    dp[1]=1;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();

        for(i=0;i<g[node].size();i++)
        {
            ll child=g[node][i];
            indegree[child]--;
            if(indegree[child]==0)q.push(child);
        }

        for(i=0;i<backedge[node].size();i++)
        {
            ll child=backedge[node][i];
            dp[node]=(dp[node]+dp[child])%mod;
        }
    }
    return dp[n];

}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll n,e,m,i,j;
    cin>>n>>e;
    for(i=0; i<e; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        backedge[v].push_back(u);
        indegree[v]++;
    }
    ll ans=top_sort(n);
    cout<<ans<<endl;

}

