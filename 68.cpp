#include <bits/stdc++.h>
using namespace std;
// All the Tree/Graph Terminologies Explained

/*

    Graph is collection of edges and vertices

    Tree is a graph which does not have a cycle 
    If tree has n nodes then it has n-1 edges

    Connected components in graphs

    if graph is this
                      1--2--3----5
                            |    |
                            |    |   
                            4-----
                        
                        7----8

        so this graph has two connected components  
        sometimes graph is also called forest

    Undirected graphs - no directed edges i.e. they are directional


    In directed graph, cycle forms when you are able to complete a circle in the directed edges
        then it is called directed cyclic graph
        otherwise it is called directed acyclic graph


    Strongly connected components in directed graphs - If you are able to move from every vertex to every other vertex in the component


    In Tree 
        - leaf node - which has no child
        - depth of a node - distance of that node from root node
        - height of a node - longest distance( count of edges ) from the leaf node of its children

            1
    2              3
4       5        6     7
               8

    thus depth of 2 is 1
    and height of 2 is also 1
    and height of 1 is 3


    LCA - lowest common ancestor (first common ancestor)
    LCA of 8 and 7 is 3
    LCA of 5 and 7 is 1

  

*/

int main() {

    

    return 0;
}