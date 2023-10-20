#include <bits/stdc++.h>
using namespace std;




// SUM OF ARRAY ********************************
// sum(n, arr) -> sum of elements up to n index
// in recursive function define the function in its own terms
// sum(n, a) = a[n] + sum(n-1, a)


// int sum(int n, int a[]){
//     if(n < 0) return 0;
//     return sum(n-1, a) + a[n];
// }
// // O(N * 1) = O(N)

// int main() {
//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
//     cout<<sum(3, a)<<"\n";

//     return 0;
// }



// DIGIT SUM **************************
// 1234 = 4 + digit_sum(123)
// digit_sum(n) -> digit_sum(n/10) + last_digit

int digit_sum(int n){
    if(n==0) return 0;
    return digit_sum(n/10) + (n % 10); 
}

int main(){
    int n;
    cin>>n;
    cout<<digit_sum(n)<<"\n";

    return 0;
}
// 1. Number of function calls -> no. of digits in n
// 2. complexity of each function call -> O(1)
// log(N) -> no. of digits in number n
// how many times we can divide N with 10 is what log(N) is ********************************
// thus O(logN) is the time complexity