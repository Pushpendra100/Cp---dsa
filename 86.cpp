#include <bits/stdc++.h>
using namespace std;
// Disjoint Set Union Practice Questions
// https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union/problems/
// https://cp-algorithms.com/data_structures/disjoint_set_union.html

// City and Flood

/*
input
4
2
1 2
4 1
output
2
*/


// const int N = 1e5+10;

// int parent[N];
// int siz[N];

// void make(int v){
//     parent[v] = v;
//     siz[v] = 1;
// }

// int find(int v){
//     if(v == parent[v]) return v; 
//     return parent[v] = find(parent[v]); 
// }

// void Union(int a, int b){  
//     a = find(a); 
//     b = find(b);
//     if(a != b){  
//         if(siz[a]< siz[b]) swap(a, b);   
//         parent[b] = a;
//         siz[a] += siz[b];
//     }
// }

// int main() {

//     int n, k;
//     cin>>n>>k;
//     for (int i = 1; i <=n; i++)
//     {
//         make(i);
//     }
//     while (k--)
//     {
//         int u, v;
//         cin>>u>>v;
//         Union(u, v);
//     }
//     int ct = 0;
//     for (int i = 1; i <=n; i++)
//     {
//         if(find(i)==i) ct++;
//     }
    
//     cout<<ct<<endl;

//     return 0;
// }






















// City and Campers


/*
input
2 1
1 2

output
0

*/

const int N = 1e5+10;
int parent[N];
int siz[N];
multiset<int> sizes;


void make(int v){
    parent[v] = v;
    siz[v] = 1;
    sizes.insert(1);
}

int find(int v){
    if(v == parent[v]) return v; 
    return parent[v] = find(parent[v]); //path compression
}

void merge(int a, int b){  //b is merged under a
    sizes.erase(sizes.find(siz[a]));
    sizes.erase(sizes.find(siz[b]));

    sizes.insert(siz[a]+siz[b]);
}

void Union(int a, int b){  
    a = find(a); 
    b = find(b);
    if(a != b){  
        if(siz[a]< siz[b]) swap(a, b);    // union by size
        parent[b] = a;
        merge(a, b);
        siz[a] += siz[b];
    }
}


int main() {

    int n, q;
    cin>>n>>q;
    for (int i = 1; i <=n; i++)
    {
        make(i);
    }
    while (q--)
    {
        int u, v;
        cin>>u>>v;
        Union(u, v);
        
        if(sizes.size()==1){
            cout<<0<<endl;
        }else{
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout<<mx-mn<<endl;
        }
    }

    return 0;
}