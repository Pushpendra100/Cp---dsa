#include <bits/stdc++.h>
using namespace std;
// Kruskal's Algorithm: Minimum Spanning Tree

/*
we have to convert a weighted undirected graph into a tree with minimum weights

Now, 
    consider all nodes to be independent
    now arrange all edges in sorted order of their weights and put them in the graph
    if after putting this edge in the tree loop is being created then don't in the tree
    if not then we can consider this edge in the msp(minimum spanning tree)

    we will put small edges untill loop is not created
    this is only kruskal's algorithm
    when my all nodes are connected then tree is formed


    we can sort in nlog(n)
    to check if loop is not created we will use dsu(disjoint set union)  

*/

/*
input
6 9
5 4 9
1 4 1
5 1 4
4 3 5   
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7

output
1 4
1 2
3 2
5 1
2 6
17

*/


const int N = 1e5+10;
int parent[N];
int siz[N];


void make(int v){
    parent[v] = v;
    siz[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v; 
    return parent[v] = find(parent[v]); 
}


void Union(int a, int b){  
    a = find(a); 
    b = find(b);
    if(a != b){  
        if(siz[a]< siz[b]) swap(a, b);    
        parent[b] = a;
        siz[a] += siz[b];
    }
}


int main() {

    int n, m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u, v}}); 
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <=n; i++) make(i);
    

    int total_cost = 0;
    for (auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        // if u and v have same parent then on joining them loop will be created
        if(find(u)==find(v)) continue;
        Union(u, v);
        total_cost += wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;

    return 0;
}