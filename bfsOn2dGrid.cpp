///bfs at 2D grid
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll N,M;
bool vis[1001][1001];
ll dis[1001][1001];
bool isvalid(ll x,ll y)
{
    if(x<1 || x>N || y<1 || y>M)return false;

    if(vis[x][y])return false;
    return true;
}
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
void bfs(ll x,ll y)
{
    queue<pair<ll,ll>>q;
    q.push({x,y});
    dis[x][y]=0;
    vis[x][y]=1;

    while(!q.empty())
    {
        ll currx=q.front().first;
        ll curry=q.front().second;
        q.pop();
        for(ll i=0;i<4;i++)//diagon are not included
        {
            if(isvalid(currx+dx[i],curry+dy[i]))
            {
                ll newx=currx+dx[i];
                ll newy=curry+dy[i];
                vis[newx][newy]=1;
                dis[newx][newy]=dis[currx][curry]+1;
                q.push({newx,newy});
            }
        }
    }
    //printing distance
    for(ll i=1;i<=N;i++)
    {
        for(ll j=1;j<=M;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll n,e,m,i,j,x,y;
    cin>>N>>M;
    cin>>x>>y;
    bfs(x,y);
    return 0;
}
