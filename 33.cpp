#include <bits/stdc++.h>
using namespace std;
// Inbuilt sort function of stl

int main() {

    // input
    // 6
    // 4 5 2 25 7 8

    // int n;
    // cin>>n;
    // int a[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin>>a[i];
    // }

    // // sort(a, a+n); 
    // // sort(a, a+2); 
    // sort(a+2, a+n); 
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }



      
    
    /*
        this sort function is called Introsort
        this is mixture of three sort - 
            - quick sort
            - heap sort
            - insertion sort

        complexity of this sort function is O(nlog(n))

    */



   int n;
   cin>>n;
   vector<int> a(n);
   for (int i = 0; i < n; i++)
   {
    cin>>a[i];
   }
   
//    sort(a.begin(), a.end());
   sort(a.begin()+2, a.end());
   for (int i = 0; i < n; i++)
   {
    cout<<a[i]<<" ";
   }
   



    return 0;
}