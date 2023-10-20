#include <bits/stdc++.h>
using namespace std;
//Binary Exponentiation : Iterative Method

// iterative codes are faster than recursion
// so always chose iterative over recursive codes


/*
    3^13

    To break a no. in power of 2 -> write its binary
    13 = 1101 = 2^3 + 2^2 + 0 + 2^0

            (1101)            (8 + 4 + 0 + 1)
    thus 3 ^         =     3 ^                 =  3^8 * 3^4 * 3^1
    thus when bit is set raise to that corresponding powers and multiply

    if b is the power then it will have log(b) bits

*/


/*

3^13 -> 3^(1101)

ans = 1

    b       a       ans
   1101     3        3
   110      3^2      - 
    11      3^4     3^5
    1       3^8     3^13
    0 -> while loop break

no. of steps = log(b), as there are log(b) bits in binary



*/


// these code are only possible for
// i.e. constraints for binExpIter and binExpRecur
// a, b < 10^9 i.e. they are int
// M ~ 10^9

const int M = 1e9+7;


int binExpIter(int a, int b){
    int ans = 1;
    while (b) // b is non-zero
    {
        if(b&1){ //0th bit is one
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M; // powers get double
        b>>=1;
    }
    return ans;
}
// time complexity = log(b)


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

    cout<<binExpIter(2,3)<<endl;

    int a = 2123123, b= 1231231;
    cout<<binExpIter(a,b)<<endl;
    cout<<binExpRecur(a,b)<<endl;

    return 0;
}