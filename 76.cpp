#include <bits/stdc++.h>
using namespace std;
// How to find Lowest Common Ancestor(LCA) in a Tree


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
6 7
*/

/*
    If we have to find LCA of 6 and 12 then
    I will store path of 6 and 12 from root
         6 - 1 2 5 6
         12 - 1 2 5 8 12
         thus 5 is the lca
*/



const int N = 1e5+10;

vector<int> g[N];
int par[N];

void dfs(int v, int p=-1){
    par[v] = p;
    for (int child : g[v]){
        if(child == p) continue;
        dfs(child, v);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while(v != 1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());     
    return ans;
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

    dfs(1);
    // O(N) as considering approx same size of vertices and edges

    int x,y; // to find lca of x and y
    cin>>x>>y;
    vector<int> path_x = path(x);  //O(N)
    vector<int> path_y = path(y); //O(N)

    int mn_ln = min(path_x.size(), path_y.size());
    int lca = -1;

    for (int i = 0; i < mn_ln; i++)
    {
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }else{
            break;
        }
    }
    // Thus time complexity - O(n)
    cout<<lca<<endl;

    return 0;
}