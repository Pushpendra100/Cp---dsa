#include <bits/stdc++.h>
using namespace std;

// void func(){
//     func();
// }

// int main() {

//     func();
//     // recursion internally works using stack,
//     // and since this func() is going on recursively
//     // this will lead to stack overflow and thus we get error
//     // segmentation fault (error related to memory)

//     return 0;
// } 



// void func(int n){
//     if(n==0) return;
//     cout<<n<<endl;
//     func(n-1); // thus before function call - operations are done jate hui direction mein
//     //  and after function call - operations are done wapas aatein hue
//     cout<<n<<endl;
    
// }

// int main(){
//     func(5);
//     return 0;
// }



// Factorial of N
// every recursive function should have a base condition to return from
int fact(int n){
    if(n==0) return 1;
    return fact(n-1) * n;
}

int main(){
    int n;
    cin>>n;
    cout<<fact(n)<<"\n";
}
// Time complexity of recursive functions
// 1. Number of function calls
// 2. what is complexity of each function
// O(N * 1) = O(N)
// if for loop is inside the function of fact then O(N * N) = O(N^2)