#include <bits/stdc++.h>
using namespace std;
// Edge Deletion Questions using DFS
// https://www.interviewbit.com/problems/delete-edge/

/*
find sum of subtree for every node and then check for every edge
*/

const int N = 1e5+7;
vector<int> g[N];
int subtree_sum[N];
int val[N];
const int M = 1e9+7;


void dfs(int v, int p = -1){
    subtree_sum[v] += val[v-1];
    for (int child : g[v])
    {
        if(child == p) continue;
        dfs(child, v);
        subtree_sum[v] += subtree_sum[child];
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

    dfs(1, 0);
    long long ans = 0;

    for (int i = 2; i <= n; i++)
    {
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = max(ans, part1 * 1LL * part2);
    }
    cout<<(ans%M)<<endl;


    return 0;
}