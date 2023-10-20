#include <bits/stdc++.h>
using namespace std;
// 0-1 BFS: What is it, How to Code with Example Question
// when we have to find shortes path and edges has unequal weight
// and edges has only two weights 0 and 1
// https://www.codechef.com/AUG14/problems/REVERSE


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
at a time only two level of nodes exist in queue


consider we are at level x and putting children of this level x+1
In x+1 level we get to have some child whose edge is 0 then we will put this child in front of queue
i.e we will bring this node to same level as x


q => 1
q => 3 2 13
q => 
q =>
q =>
q =>
q =>
q =>
q =>
q =>
q =>

In 0-1 bfs we don't need visited array  
and we use deque because we can put elements in front of it aslo 
(in queue we can only put elements in the back)
*/



/*
now in question

consider all exist directed edges as of 0 weight
and now you put edge opposite to thsee edges and it has weight 1

we have to find shortest path to 7
and find the minimum no. of 1 for that and we have to return the count of 1 only i.e. how many edges do we need to reverse                                                                                                                                                                                                                                                                                                  

We will use 0-1 bfs here
*/


/*
input
7 7
1 2
3 2
3 4
7 4
6 2
5 6
7 5

output
2
*/

const int N = 1e5+10;
const int INF = 1e9+10;


vector<pair<int,int>> g[N];
vector<int> level(N, INF);
int n, m;


int bfs(){
    deque<int> q;
    q.push_back(1);
    level[1] = 0;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();

        for (auto child : g[cur_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if(level[cur_v]+wt < level[child_v]){ //i.e. the node is not visite till now
                level[child_v] = level[cur_v] + wt;
                if(wt == 1){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }
            // every node can be processed max of 2 times
        }
    }
    return level[n] == INF? -1:level[n];
    
}

int main() {

    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==y) continue;      //here we don't need to consider self loop 
        g[x].push_back({y,0});      // we are only give edge from x to y
        g[y].push_back({x,1});      // we will put reverse edge ourself with weight 1
    }
    
    cout<<bfs()<<endl;
    return 0;
}