#include <bits/stdc++.h>
using namespace std;
// How to DFS in a TREE 

/*
depth of a node - the distance from the node
height of a node - maximum distance between this node and leaf node from its subtree

height of leaf node = 0
for a node we have to get height of each of its child node because we want to take maximum height

    1   2   3   4   5   6   7   8   9   10  11  12  13      
d   0   1   1   2   2   3   3   3   3   3   4    4   1                                         
h   4   3   3   2   2   0   0   1   0   0   0    0   0
*/

/*
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
*/





const int N = 1e5+10;

vector<int> g[N];
int depth[N], height[N];


void dfs(int vertex, int par = 0){
    for (auto &child : g[vertex])
    {
        if(child == par) continue;
        //before entering the child
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        //after leaving the child
        height[vertex] = max(height[vertex], height[child]+1);
    }
}


int main() {

    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)   // there are n-1 edges in trees
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
    

    return 0;
}