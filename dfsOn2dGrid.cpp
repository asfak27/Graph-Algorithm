///Counting Connected Components in Grid applying dfs
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll N,M;
bool vis[1001][1001];
ll a[1001][1001];
bool isvalid(ll x,ll y)
{
    if(x<1 || x>N || y<1 || y>M)return false;

    if(vis[x][y] || a[x][y]==0)return false;
    return true;
}
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
void dfs(ll x,ll y)
{
    vis[x][y]=1;
   // cout<<x<<" "<<y<<endl;
    for(ll i=0;i<4;i++)
    {
        if(isvalid(x+dx[i],y+dy[i]))
        {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll n,e,m,i,j;
    cin>>N>>M;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            cin>>a[i][j];
        }
    }
    ll c=0;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(vis[i][j]==0 && a[i][j]==1)
            {
                dfs(i,j);
                c++;
            }
        }
    }
    cout<<c<<endl;

    return 0;
}
/*
6 6
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0
0 1 1 0 1 1
*/

/*
///apply dfs on grid
#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll N,M;
bool vis[1001][1001];
bool isvalid(ll x,ll y)
{
    if(x<1 || x>N || y<1 || y>M)return false;

    if(vis[x][y])return false;
    return true;
}
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
void dfs(ll x,ll y)
{
    vis[x][y]=1;
    cout<<x<<" "<<y<<endl;
    for(ll i=0;i<4;i++)
    {
        if(isvalid(x+dx[i],y+dy[i]))
        {
            dfs(x+dx[i],y+dy[i]);
        }
    }
    if(isvalid(x-1,y))dfs(x-1,y);

    if(isvalid(x,y+1))dfs(x,y+1);

    if(isvalid(x+1,y))dfs(x+1,y);

    if(isvalid(x,y-1))dfs(x,y-1);
}
int main()
{
    //freopen("textnew.txt","r",stdin);
    ll n,e,m,i,j;
    cin>>N>>M;
    dfs(1,1);
    return 0;
}
*/

