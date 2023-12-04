#include<bits/stdc++.h>
using namespace std;
int xm[4] = { -1, 0, 0, 1};
int ym[4] = {0, 1, -1, 0};
int n,m;
int  arr[100][100];
bool vis[100][100]= {false};

void dfs(int i,int j)
{
    vis[i][j] =true;
    for(int l =0;l<4;l++)
    {
        int tx = i + xm[l];
        int ty = j + ym[l];
        if(tx>=0 && tx <n && ty>=0 && ty<m && vis[tx][ty]== 0 && arr[tx][ty] ==1)
        {
            dfs(tx,ty);
        }

    }
}

int main()
{
    int k;
    cin>>n>>m>>k;

    for(int i=0; i<n; i++)
        for(int j =0; j<m; j++)
            cin>>arr[i][j];
    int cnt =0;

    for(int i=0; i<n; i++)
        for(int j =0; j<m; j++)
        {
            if(arr[i][j] ==1 && vis[i][j] == false)
            {
                cnt+=1;
                dfs(i,j);
            }
        }
    if(cnt<= k)
        cout<<"HAPPY\n";
    else
        cout<<"SAD\n";
}
