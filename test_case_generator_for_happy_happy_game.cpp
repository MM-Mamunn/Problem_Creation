#include<bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define forc(c,n) for(int i=c;i<n;i++)
#define el "\n"

int dx[]= {-1, 1, 0, 0, -1,-1, 1, 1};
int dy[]= { 0, 0,-1, 1, -1, 1,-1, 1};


ll arr[100][100];
ll vis[100][100]= {0};
ll n= 17,m=13;

void dfs(ll ii,ll j)
{
    vis[ii][j]=1;
    forc(0,4)
    {
        ll tx = ii + dx[i];
        ll ty = j + dy[i];
        if(tx>=1 && tx<=n && ty>=1 && ty<=m && vis[tx][ty] == 0 && arr[tx][ty] == 1)
            dfs(tx,ty);
    }
}
void check(ll n, ll m )
{
    forc(1,n+1)
    {
        for(int j =1 ; j<=m; j++)
            cin>>arr[i][j];
    }
    memset(vis,0,sizeof(vis));
    cout<<el<<el;
    ll cnt =0;
    forc(1,n+1)
    {
        for(int j =1 ; j<=m; j++)
        {
            if(vis[i][j]==0 && arr[i][j] == 1)
            {
                cnt +=1;
                dfs(i,j);
            }
        }
    }
    cout<<"cnt "<<cnt<<el;
}

int main()
{
    ///remove comment of next two line to find the number of components that is the number of minimum pot required
    // check(n,m);
    //return 0;
   /// n & m declared globally
    forc(1,n+1)
    {
        for(int j =1 ; j<=m; j++)
        {
            /// random condition to generate 1
            if(i % 2 && j % 3 == 2)
                cout<<1<<" ";
            else
                cout<<0<<" ";

        }
        cout<<el;
    }
    return 0;
}



