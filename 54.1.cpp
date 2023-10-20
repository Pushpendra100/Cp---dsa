#include <bits/stdc++.h>
using namespace std;
// Binary Exponentiation : Recursive Method
// it was needed due to precision errors


const int M = 1e9+7;

// // without modulo
// long long binExpRecur(int a, int b){

//     if(b==0) return 1;

//     long long res = binExpRecur(a, b/2);  // call function once and store it in value to avoid unncecessary calls    
//     if(b&1){
//         //odd
//         // return a * binExpRecur(a, b/2) * binExpRecur(a, b/2); // this would be calling function unnecessary times 
//         return a * res * res;
//     }else{
//         // return binExpRecur(a, b/2) * binExpRecur(a, b/2);
//         return res * res; 
//     }
// }

// // with modulo
int binExpRecur(int a, int b){
    if(b==0) return 1;
    int res = binExpRecur(a, b/2);      
    if(b&1){
        return (a * ((res * 1LL * res) % M) ) % M;
    }else{
        return (res * 1LL * res) % M; 
    }
}

int main() {
    // // cout<<pow(2,3);

    // double d = 1e20;
    // cout<<d<<endl;                           //1e+20
    // cout<<setprecision(30)<<d<<endl;         //100000000000000000000
    // cout<<fixed<<setprecision(30)<<d<<endl;  //100000000000000000000.000000000000000000000000000000

    // double d1 = 1e24;
    // cout<<fixed<<setprecision(30)<<d1<<endl; //999999999999999983222784.000000000000000000000000000000

    // // thus double can store very large values but does not accurately store them,
    // // so we can't rely on them, thus we avoid using double
    // // and pow(2, 3) returns double value
    // // thus we don't use this 
    // // and thus we use binary exponentiation and sometimes using them with modulo also
    // // a^b % m








    // int a = 2, b = 13;
    // int ans = 1;
    // for (int i = 0; i < b; i++)
    // {
    //     ans *= a;
    //     ans %= M;
    // }
    // // O(b)
    // cout<<ans<<endl;

    // // but this O(n) time complexity is not good for calculating power
    






    /*
        ****Divide and Conquer********
        a^b
        2^16 = 2^8 * 2^8
        2^8  =  2^4 * 2^4
        2^4  =  2^2 * 2^2
        2^2  = 2^1 * 2^1

        // this takes log2(b) time


        for odd power
        3^13 = 3 * 3^12
        3^12 = 3^6 * 3^6
        3^6 = 3^3 * 3^3
        3^3 = 3 * 3^2
        3^2 = 3^1 * 3^1
        3^1 = 3 * 3^0


        this is only called binary exponentiation and can be done in two ways
            - recursive method
            - iterative method



        f(a, b) -- b is even --> f(a, b/2) * f(a, b/2)
        f(a, b) -- b is odd  --> a * f(a, b/2) * f(a, b/2)
        if (b == 0) return 1;
    */


    cout<<binExpRecur(5, 10)<<endl;
    cout<<pow(5, 10)<<endl;




    return 0;
}