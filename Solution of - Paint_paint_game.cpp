#include<bits/stdc++.h>
using namespace std;

int n ,m;
int  arr[100][100];
bool vis[100][100]={false};

void bfs(int i,int j)
{
    vis[i][j] =true;
    queue<pair<int ,int >>q;
    q.push({i,j});
    while(!q.empty())
    {
        pair <int ,int > t = q.front();
        q.pop();
        vis[t.first][t.second]=true;

        if((t.second+1)<m && vis[t.first][t.second+1] == false && arr[t.first][t.second+1] ==1 )
            q.push({t.first,(t.second+1)});
        if((t.second-1)>=0 && vis[t.first][t.second-1] == false && arr[t.first][t.second-1]==1 )
            q.push({t.first,(t.second-1)});
        if((t.first +1)<n && vis[t.first+1][t.second] == false && arr[t.first+1][t.second] ==1 )
            q.push({(t.first+1),(t.second)});
        if((t.first -1)>=0 && vis[t.first-1][t.second] == false && arr[t.first-1][t.second] ==1 )
            q.push({(t.first-1),(t.second)});
    }
}



int main()
{

cin>>n>>m;

for(int i=0;i<n;i++)
    for(int j =0;j<m;j++)
        cin>>arr[i][j];
int cnt =0;

for(int i=0;i<n;i++)
    for(int j =0;j<m;j++)
    {
        if(arr[i][j] ==1 && vis[i][j] == false)
        {
            cnt+=1;
            bfs(i,j);
        }
    }
if( cnt == 1)
{
    cout<<"mono"<<endl;
    cout<<1<<endl;
}
else
{
    cout<<"poly"<<endl;
    cout<<cnt<<endl;
}
}