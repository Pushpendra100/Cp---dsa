#include <bits/stdc++.h>
using namespace std;
// Pre-Computation using DFS | Subtree Queries



/*
Given Q queries, Q<= 10^5
In each query given V,
print subtree sum of V & Number of even numbers in subtree of V
*/


/*
we need to give value array, which contains value of each node
so for simplicity here we are giving value same as their node number


sum of subtree of leaf node is its own value only

        1   2   3   4   5   6   7   8   9   10  11  12  13      
s.s     91  40  37  34  38  6   7   20  9   21  11  12  13
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
int subtree_sum[N];
int even_ct[N];

int val[N]; // if value array given then simply we can use this no. instead of using the vertex itself

void dfs(int vertex, int par = 0){
    subtree_sum[vertex] += vertex;
    if(vertex%2==0) even_ct[vertex]++;
    for (int &child : g[vertex])
    {
        if(child == par) continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex]+=even_ct[child];
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
    for (int i = 1; i <=n; i++)
    {
        cout<<subtree_sum[i]<<" "<<even_ct[i]<<"\n";
    }
    

    // int q;
    // while(q--){
    //     int v;
    //     cin>>v;
    //     cout<<subtree_sum[v]<<" "<<even_ct[v]<<"\n";
    // }

    return 0;
}