#include <bits/stdc++.h>
using namespace std;

// int main() {

//     // SELECTION SORT *******************
//     // one by one put the minimum from the unsorted subarray to the front

//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         int minIndex = i;
//         for (int j = i+1; j < n; j++)
//         {
//             if(a[j]< a[minIndex]){
//                 minIndex = j;
//             }
//         }
//         swap(a[i],a[minIndex]);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout<<a[i]<<" ";
//     }
    
//     // Time Complexity - O(N^2)
    

//     return 0;
// }







// MERGE SORT *************************************
// -> merge -- merging two sorted arrays
// -> sort

/*  merging step  -step of mergin two sorted arrays

    compare first elements and put smaller one 
    _3_ 27 38 43 and _9_ 10 82   -> 3          
    _27_ 38 43  and  _9_ 10 82  -> 3 9
    27 38 43  and 10 82 -> 3 9 10
    27 38 43  and 82 -> 3 9 10 27
    38 43 and 82 -> 3 9 10 27 38
    43 and 82 -> 3 9 10 27 38 43 
    82 -> 3 9 10 27 38 43 82

    let first array be of size n and second one be of m
    and final array is n+m and we have put one item at a time
    thus 
    O(n+m) is time complexity
*/

/*
38 27 43 3 9 82 10 is the given array, divide this into two halves
38 27 43 3 and  9 82 10
38 27 43  |  3                     9 82 | 10
38 27  |  43    | 3               9  | 82  | 10
38   | 27    | 43     |  3          9   | 82    | 10
array of one element is always sorted
thus here comes the step of mergin two sorted arrays

27 38    |        3    43                |      9 82           |     10
3   27    38    43                   |            9   10   82
3  9  10  27  38   43    82
this is our final 
*/



const int N = 1e5+10;
int a[N];

void merge (int l, int r, int mid){
    int l_sz = mid - l + 1;
    int L[l_sz + 1];
    int r_sz = r - mid;
    int R[r_sz + 1];
    for (int i = 0; i < l_sz; i++)
    {
        L[i] = a[i+l];
    }
    for (int i = 0; i < r_sz; i++)
    {
        R[i] = a[i+mid+1];
    }
    L[l_sz] = R[l_sz] = INT_MAX; // it will help when actually one array ends but other array is still remaining and it can compare its value from the int_max of empty array and
    // we be going in the new array

    int l_i = 0;
    int r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if(L[l_i] <= R[r_i]){
            a[i] = L[l_i];
            l_i++;
        }else{
            a[i] = R[r_i];
            r_i++;
        }
    }
}

void mergeSort(int l, int r){
    if(l==r) return;
    int mid = (l+r)/2;
    mergeSort(l, mid);
    mergeSort(mid+1, r);
    merge(l, r, mid);
}
// Time Complexity 
// N -> N/2 -> N/4 -> ....      we can divide N by 2, log2(N) times
// and N computations in each step to combine them
// O(Nlog2N) this is time complexity


int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    mergeSort(0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
       
}