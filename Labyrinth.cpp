#include <bits/stdc++.h>
using namespace std;
int n, m;
char graph[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> parent;
vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int cnt = 0;
vector<char> vec;
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    // cout<<si<<" "<<sj<<endl;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && graph[ci][cj] == 'B') {
            vis[ci][cj] = true;
            return;
        }
        if (valid(ci, cj) && !vis[ci][cj] && graph[ci][cj] == '.')
        {   
            if(d[i].first == 0 && d[i].second == -1) vec.push_back('L');
            if(d[i].first == 0 && d[i].second == 1) vec.push_back('R');
            if(d[i].first == -1 && d[i].second == 0) vec.push_back('U');
            if(d[i].first == 1 && d[i].second == 0) vec.push_back('D');
            // cnt++
            parent.push_back({si,sj});
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj;
    int di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            else if (graph[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(parent,-1,sizeof(parent));
    dfs(si,sj);
    if(vis[di][dj]==true){
        cout<<"YES"<<endl;
        cout<<cnt<<endl;
        for(char c : vec){
            cout<<c;
        }
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}