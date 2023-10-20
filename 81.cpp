#include <bits/stdc++.h>
using namespace std;
// Multi Source BFS: Tutorial with Code & Example Question
// https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/

/*
we have to reach a certain node in less distance and we have three sources and we have to decide where to start from 

in multi source bfs, we put all source in the queue from where we need to start bfs
q => s1, s2, s3

we know at a time queue has two levels

thus when we are putting all sources in queue at starting 
this means these all have same level 0
and children of all these three will be of level1
*/



/*
input
3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2

output
0
1
2
*/


const int N = 1e3+10;
const int INF = 1e9+10;
int val[N][N];
int vis[N][N];
int lev[N][N];
int n, m;

vector<pair<int,int>> movements = {{0,1},{0,-1},{1,0},{-1,0},{1, 1},{-1, -1},{-1,1},{1, -1}};

bool isValid(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}

//we have to tell minimum no. of hours in which 
int bfs(){
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, val[i][j]);
        }
    }
    // this bfs is on grid thus we will use pair
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mx==val[i][j]){
                q.push({i,j});
                lev[i][j] = 0;
                vis[i][j] = 1; 
            }
        }
    }

    int ans = 0;

    while (!q.empty())
    {
        auto v = q.front();
        int v_x = v.first;
        int v_y = v.second;
        q.pop();

        for (auto movement : movements)
        {
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if(!isValid(child_x, child_y)) continue;
            if(vis[child_x][child_y]) continue;
            q.push({child_x,child_y});
            lev[child_x][child_y] = lev[v_x][v_y] + 1;
            vis[child_x][child_y] = 1;
            ans = max(ans, lev[child_x][child_y]);
        }
    }
    return ans;
}


void reset(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}

int main() {

    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        reset();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>val[i][j];
            }
        }
        cout<<bfs()<<endl;
    }

    return 0;
}