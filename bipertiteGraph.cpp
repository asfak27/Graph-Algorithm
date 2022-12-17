#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll         int
//#define  mod      1000000007
#define  N         1000005
#define yes      cout<<"Yes"<<endl
#define no      cout<<"No"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
ll vis[N],color[N];
bool f=true;
void bfs(ll source)
{
    queue<ll>q;
    vis[source]=1;
    q.push(source);
    color[source]=0;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();

        for(ll i=0;i<g[node].size();i++)
        {
            ll child=g[node][i];

            if(color[child]==-1)
            {
                color[child]=1-color[node];
                q.push(child);
            }
            else if(color[child]==color[node])
            {
                f=false;
                return;
            }
        }
    }
}

void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v,p;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,z,x,r,k,y;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(color,-1,sizeof(color));
    for(i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            bfs(i);
        }
    }
    if(f)
    {
        for(i=1;i<=n;i++)
        {
            if(color[i]==0)v.push_back(i);
            else p.push_back(i);
        }
        cout<<v.size()<<endl;
        for(i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        cout<<p.size()<<endl;
        for(i=0;i<p.size();i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
        return;
    }
    cout<<-1<<endl;
}
int main()
{
    fast;
    int T=1;
   // cin>>T;
    while(T--)solve();
    return 0;
}



/*
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define  mod      1000000007
#define  N         2005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll g[N][N]={0,0};
ll vis[N],dis[N],color[N],c,n;
bool bfs(ll source)
{
    queue<ll>q;
    q.push(source);
    color[source]=1;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(ll i=1;i<=n;i++)
        {
            if (g[node][i] &&color[node]==color[i])
            {
                return false;
            }
            else if(g[node][i] && color[i]==-1)
            {
                color[i]=1-color[node];
                q.push(i);
            }
        }
    }
    return true;

}


void solve()
{
    //freopen("textnew.txt","r",stdin);

   // memset(g,0,sizeof(g));
    vector<ll>v;
    map<ll,ll>mp;
    ll e,i,j,l,m,z,x,r,k;
    cin>>n>>m;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            g[i][j]=0;
        }
    }

    for(i=0; i<m; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;
    }
    for(i=1; i<=n; i++)
    {
        color[i]=-1;
    }
    bool f=true;
    for(i=1; i<=n; i++)
    {
        if(color[i]==-1)
        {
            if(!bfs(i))
            {
                f=false;
                break;
            }
        }
    }
    c++;
    if(!f)
        printf("Scenario #%d:\nSuspicious bugs found!\n",c);
    else
        printf("Scenario #%d:\nNo suspicious bugs found!\n",c);

}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}

/*
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define  mod      1000000007
#define  N         200005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
ll vis[N],col[N],n,d;
bool dfs(ll node,ll c)
{
    vis[node]=1;
    col[node]=c;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(vis[child]==0)
        {
            if(!dfs(child,c^1))
            {
                return false;
            }
        }
        else
        {
            if(col[node]==col[child])return false;
        }
    }
    return true;
}
void solve()
{
    //freopen("textnew.txt","r",stdin);

    vector<ll>v;
    map<ll,ll>mp;
    ll e,i,j,l,m,z,x,r,k;
    cin>>n>>m;
    for(i=0;i<=n;i++)
    {
        g[i].clear();
        vis[i]=0;
        col[i]=0;
    }
    for(i=0; i<m; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool f=true;
    for(i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            if(!dfs(i,0))
            {
                f=false;
                break;
            }
        }
    }
    d++;
    if(!f)
        printf("Scenario #%d:\nSuspicious bugs found!\n",d);
    else
        printf("Scenario #%d:\nNo suspicious bugs found!\n",d);

}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}



*/
