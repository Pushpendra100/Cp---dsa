#include <bits/stdc++.h>
using namespace std;
// How To Represent Trees and Graphs in Code

/*
************Adjacency Matrix*****************


## undirected graph
0----1-----2
this is our graph

v= 3 and e= 2
make a matrix of v * v
and fill a[i][j] = 1 if i and j are connected
// and since this is undirected graph then if a[i][j] is 1 then a[j][i] is also to be marked as 1
   0   1   2
0  0   1   0
1  1   0   1  
2  0   1   0


## directed graph
let's suppose this is directed graph then
0---->1<-----2


   0   1   2
0  0   1   0
1  0   0   0  
2  0   1   0
this is adjacenct matrix


## undirected graph with weights

   2    3 
0----1-----2

then value of a[i][j] = wt and it will be same for a[j][i] as well since it is undirected
   0   1   2
0  0   2   0
1  2   0   3  
2  0   3   0

same we can do for directed as well




####
graph input are given with
    N -> vertices
    M -> no. of edges
    and then in M line edges are given
     1 - 2
     2 - 3
     3 - 4
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

// const int N = 1e3+10;
// int graph[N][N];

// int main() {

//     int n, m;
//     cin>>n>>m;
//     for (int i = 0; i < m; i++)
//     {
//         int v1, v2;
//         cin>>v1>>v2;
//         graph[v1][v2] = 1;
//         graph[v2][v1] = 1;
//     }
//     // O(N^2) this is the space complexity
//     // N = 10^6 then i can't make graph of n^2, max size of matrix can be ~ 10^7
//     // in those cases we can't use this method for storing very large graphs




//     return 0;
// }









/*
**********Adjacency List***************

0----1-----2

0 -> 1
1 -> 0, 2
2 -> 1

space complexity = O(V + E)    where V - vertices and E - edges
adjacency list is better than adjacency matrix

*/



// const int N = 1e3+10;
// vector<int> graph2[N];

// int main(){
//     int n, m;
//     cin>>n>>m;
//     for (int i = 0; i < m; i++)
//     {
//         int v1, v2;
//         graph2[v1].push_back(v2);
//         graph2[v2].push_back(v1);
//     }
//     //O(n+m) -> space complexity in adjacency list
//     // n <= 10^5, e < 10^7 

    
// }




/*
for weighted graph
*/

/*
input
6 9
1 3 4
1 5 3
3 5 2
3 4 7
3 6 8
3 2 9
2 6 1
4 6 2
5 6 3
*/

const int N = 1e3+10;
vector<pair<int,int>> graph3[N];

int main(){
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;

        graph3[v1].push_back({v2,wt});
        graph3[v2].push_back({v1,wt});
    }
    
}


    /*
    Adjacency matrix
    O(N^2) -- space complexity
    N <= 10^3


    Adjacency List
    O(N+M)
    N = 10^5, E < 10^7
    */

     
    /*
    Benefit of adjacency matrix
     If my questions are i, j are connected? and what is the weight of i and j
     matrix can give this answer in O(1)

     if(graph1[i][j] ==1 ){
        //connected
     }
     wt = graph1[i][j]

    but for finding in adjacency list
    we have to use loop

    for(pair<int,int> child : graph[i]){
        if(child.first == j){
            //connected
            wt = child.second   
        }
    }
    // this is O(n)loop
    */