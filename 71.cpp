#include <bits/stdc++.h>
using namespace std;
// How to find Connected Components and Cycle in a Graph using DFS 
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

/*
input
8 5
1 2
2 3
2 4
3 5
6 7

output
3
*/


const int N = 1e5+10;

vector<int> g[N];
bool vis[N];

vector<vector<int>> cc; //for storing connected components
vector<int> current_cc;

void dfs(int vertex){
    current_cc.push_back(vertex);
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        if(vis[child]) continue;
        dfs(child);
    }
}

bool dfs2(int vertex, int par){
    vis[vertex] = true;
    bool isLoopExists = false;
    for (int child : g[vertex])
    {
        if(vis[child] && child == par) continue;
        if(vis[child]) return true;
        isLoopExists |= dfs2(child, vertex);
    }
    return isLoopExists;
}

int main() {

    int n, e;
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    // // we have to run dfs for every node if it is not visited
    // int ct = 0;  // we will increase it when dfs is called

    // for (int i = 1; i <= n; i++)
    // {
    //     if(vis[i]) continue;
    //     current_cc.clear();
    //     dfs(i);
    //     cc.push_back(current_cc);
    //     ct++;
    // }

    // cout<<cc.size()<<endl;
    // for (auto &c_cc : cc)
    // {
    //     for (int vertex : c_cc)
    //     {
    //         cout<<vertex<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    // // O(n+e)
    






    //Cycle detection
    //if we comes across a node which is already visited then it is a cycle
    //except the node from which it came from, thus need to track the parent

    /*
    input
    8 6
    1 2
    2 3
    2 4
    3 5
    6 7
    1 5

    output
    1
    */

    // until it is mentioned in question we assume that are connected components in the graph

    bool isLoopExists = false;
    for (int i = 1; i <= n; i++)
    {
        if(vis[i]) continue;
        if(dfs2(i,0)){
            isLoopExists = true;
            break;
        }
    }
    cout<<isLoopExists<<endl;









    return 0;
}