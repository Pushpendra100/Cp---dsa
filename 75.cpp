#include <bits/stdc++.h>
using namespace std;
// How to find Diameter of a Tree


/*
take any root and find node with max depth -- this would be the one end of the diameter
thus take this node as root and apply dfs and thus max depth node now will be another end of diameter
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
int depth[N];

void dfs(int v, int par=-1){
    for (int child : g[v])
    {   
        if(child == par) continue;
        depth[child] = depth[v] + 1;
        dfs(child, v);
    }
}

int main() {

    int n;
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1); // we call dfs considering any one as root node, here we considered 1
    int mx_depth = -1;
    int mx_d_node;
    for (int i = 1; i <=n; i++)
    {
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }

    dfs(mx_d_node);
    mx_depth = -1;
    for (int i = 1; i <=n; i++)
    {
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }
    
    cout<<mx_depth<<endl;
    // This is O(n) time complexity

    return 0;
}