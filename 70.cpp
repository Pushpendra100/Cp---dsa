#include <bits/stdc++.h>
using namespace std;
// Depth First Search

/*
                        1

            2           3           4
        5   6   7       8
            9

    dfs start from root node then
        move to one child and goes deep into it and complete it 
        then moves to another child and then goes deep into it and complete it
        .
        and when all child complete then return


    we keep a visited array of size of the no. of vertices to keep record that we have visisted the node or not
    this vis array is must needed in graphs but not in trees, you will learn more this in trees




    consider a graph
     1 3
     1 5
     5 3
     5 6
     3 2
     3 6
     3 4
     4 6
     2 6
    undirected graph

    1 2 3 4 5 6
    1       
    1       1
    1   1   1
    1   1 1 1
    1   1 1 1 1 
    1 1 1 1 1 1

    and now since 2's children all are visited and thus now returns back

    dfs can have multiple ways as we have multiple choices for children 


*/



/*
input
6 9
1 3
1 5
3 5
3 4
3 6 
3 2
2 6
4 6
5 6
*/


const int N = 1e5+10;

vector<int> g[N];
bool vis[N];

// void dfs(int vertex){
//     // Take action on vertex after entering the vertex
//     for (int child : g[vertex])
//     {
//         //Take action on child before entering the child node
//         dfs(child);
//         //Take action on child after exiting the child node
//     }
//     //Take action on vertex before exiting the vertex
// }
// //This is the basic model of dfs


void dfs(int vertex){
    // Take action on vertex after entering the vertex
    cout<<vertex<<endl;
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        cout<<"par "<<vertex<<", child "<<child<<endl;
        if(vis[child]) continue;
        //Take action on child before entering the child node
        dfs(child);
        //Take action on child after exiting the child node
    }
    //Take action on vertex before exiting the vertex
}
// TC:- O(V+E)
// dfs is called jitni bar vertex hai
// and each dfs function has a for loop of no. of edges, but across all recursion calls this number will be equal to all the no. of edges

int main() {

    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);

    return 0;
}