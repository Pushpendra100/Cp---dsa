#include <bits/stdc++.h>
using namespace std;
// Dijkstra Algorithm
// https://leetcode.com/problems/network-delay-time/description/

/*
one source and multiple destination
priority queue - stores in an order


pq      Dist        Vis
        1 inf 0
        2 inf 1
        3 inf 5/ 3
        4 inf 3
        5 inf 2
        6 inf 4

we are trying to decrease the distance every time

priority queue => (0,1)
priority queue => (1, 2), (5, 3)
remove that whose distance is least //priority queue can find min in log(n)
and when we are removing the item out we will process it only if it is not visited

*/

const int N = 1e3+10;
const int INF = 1e9+10;
vector<pair<int,int>> g[N];

void dijkstra(int source){
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);

    //  we can use multiset instead of priority queue, declaring multiset is much easier 
    // we can still use set

    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;

    while (st.size()>0)
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if(vis[v]) continue;
        vis[v] = 1;  // one time node is get out of set then it can't enter again
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if(dist[v]+wt < dist[child_v]){  //if visited node is coming as a child and it is possible to reduce its distance then we can do this here
                dist[child_v] = dist[v] + wt;   
                st.insert({dist[child_v], child_v}); 
            }
        }
        
    }
    
}
// time complexity:- O(V + Elog(V))
// log(V) is the time complexity of insert in set

int main() {

    int n, m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin>>x>>y>>wt;
        g[x].push_back({y, wt});
        // g[y].push_back({x, wt}); // if undirected then do this also
    }
    

    return 0;
}