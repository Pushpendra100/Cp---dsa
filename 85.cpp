#include <bits/stdc++.h>
using namespace std;
// Disjoint Set Union (DSU)

/*
disjoint set union is a data structure and it has three functions
- make -> add a new node
- find -> return the root of the group
- union -> a complete and b complete group will combine, and groups are formed in the form of tree

1 2 3 4 are four independent nodes formed using make of 1, make of 2, make of 3 and make of 4
parent of 1 is 1 only
thus find(1) will return 1
union(1,2) forms
1 <-- 2   this is tree
union(3, 4) forms
3 <-- 4 this is a tree

now find(2) = 1 as 1 is the parent
    find(1) = 1 also ( returns the root of the group )

now union(2, 4)  // when we are joining two groups, we join their root node

        1
    2       3
                4
2 and 3 are pointing to 1 and 4 is pointing to 3 
now find(4) will give 1

*/



// const int N = 1e5+10;


// int parent[N];


// void make(int v){
//     parent[v] = v;
// }

// int find(int v){
//     if(v == parent[v]) return v; //independent node
//     return find(parent[v]);
// }

// int Union(int a, int b){  //union is reserved keyword thus we can not use it, thus we are using Union
//     a = find(a); // we will get the root of group in which a is present
//     b = find(b);
//     if(a != b){  //both are in different group
//         parent[b] = a;
//     }
// }

/*
if we are adding a big tree under a small tree then depth of total tree is increase by 1 and thus find operation becomes expensive
and if we add a small tree under big tree then the depth of total tree remains the same

thus now we can't add tree b under a always, and 
thus we have two ways to compare tree by size or by rank -> both have same time comlexity
this is called union by size or by rank



Path compression
                1
                2
        3              4          
    5       6
    7       8


after calling find(7), then tree will look like this
we can compress it

                    1
            2   3       5   7
            4   6
                8

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
    return parent[v] = find(parent[v]); //path compression
}

void Union(int a, int b){  
    a = find(a); 
    b = find(b);
    if(a != b){  
        if(siz[a]< siz[b]) swap(a, b);    // union by size
        parent[b] = a;
        siz[a] += siz[b];
    }
}


/*
time complexity after optimization
TC:- O(α(n))   - amortrized time complexity

α(n) is called reverse ackermann function
value very slowly increases
i.e. over the number of operations this is almost constant
*/

int main() {

    int n,k;
    cin>>n>>k;
    for (int i = 1; i <=n; i++)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin>>u>>v;
        Union(u,v);
    }

    int connected_ct = 0;        //count of connected components

    for (int i = 1; i <=n; i++)
    {
        if(find(i)==i) connected_ct++;
    }
    
    
    

    return 0;
}