#include <bits/stdc++.h>
using namespace std;
// Breadth First Search


/*


nodes 1  2  3  4  5  6  7  8  9  10  11  12  13
vis   1  1  1  1  1  1  1  1  1   1   1   1   1 

// the number which is entering in queue is marked 1 in visited array
// and the number is pop out and its children are put in the queue
q => 1
q => 2 3 13
q => 3 13 5
q => 13 5 4     // 13 will also try to put its children in the queue but it has not any children and 1 is already visited, thus it cannot put 1 
q => 5 4
q => 4 6 7 8
q => 6 7 8 9 10
q => 7 8 9 10
q => 8 9 10
q => 9 10 12
q => 10 12
q => 12 11
q => 11
q => 

this is how level is traversed                                                                                                          

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
9 11
*/

/*
When edges do not have weight or they have equal weight
then bfs level gives the shortes path from the source vertex in the graph

*/

const int N = 1e5+10;
vector<int> g[N];
int vis[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child: g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                level[child] = level[cur_v] + 1;
            }
        }
    }
}
// while loop is running V time as every time one node is being removed from queue
// and in this whole while loop iterations, for loop will run approx 2 * E   ( E - edges) times  ~ E
// O(V+E)

int main() {

    int n;
    cin>>n;

    for (int i = 0; i < n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);
    cout<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<<i<<": "<<level[i]<<endl;  
    }
    

    return 0;
}