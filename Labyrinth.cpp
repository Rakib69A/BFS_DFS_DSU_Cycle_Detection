#include <bits/stdc++.h>
using namespace std;
int n, m;
char graph[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> parent;
vector<pair<int, int>> d = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int cnt = 0;
vector<char> vec;
int si, sj;
int di, dj;
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    bool flag = false;
    while (!q.empty())
    {
        if (flag == true)
            break;
        pair<int, int> p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && (graph[ci][cj] == '.' || graph[ci][cj]=='B'))
            {
                if(graph[ci][cj] == 'B')
                    vec.push_back('X');
                if (d[i].first == 0 && d[i].second == -1)
                    vec.push_back('L');
                else if (d[i].first == 0 && d[i].second == 1)
                    vec.push_back('R');
                else if (d[i].first == -1 && d[i].second == 0)
                    vec.push_back('U');
                else if (d[i].first == 1 && d[i].second == 0)
                    vec.push_back('D');
                
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
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
    // memset(parent,-1,sizeof(parent));
    bfs(si, sj);
    if(vis[di][dj]){
        cout<<"YES"<<endl;
        cout<<vec.size()<<endl;
        for(char c : vec){
            cout<<c;
        }
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}