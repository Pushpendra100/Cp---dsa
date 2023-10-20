#include <bits/stdc++.h>
using namespace std;
// https://www.hackerearth.com/problem/algorithm/monk-and-his-father-93b639f4/

/*
let initially he took x1 amount from god, then series will go like this
    G- x1
    F - 2x1
    G - 2x1 + x2
    F - 2(2x1 + x2) = 2^2x1 + 2x2
    G - 2(2x1 + x2) + x3
    F - 2(2(2x1 + x2) + x3) = 2^3x1 + 2^2x2 + 2x3
    ...
    ...
    ...

    let after n days our amount is fullfilled
    so after n days
     =  2^nx1 + 2^(n-1)x2 + .... + 2^2x(n-1) + 2x(n)  ----
                                                          |  
                                                          |  
     we have to minimize money taken from god             |  
     which is x1 + x2 + x3 + x4 + .....+ xn               |
                                                          |  
     this is looking like          <-----------------------                       
     how we convert binary to decimal 

    since we want to minimize this x1 + x2 + x3 + x4 + .....+ xn 
    we can take 0 or 1 from god every time, we can't take 0 every time from god

    and even if we are taking 1 from god then we can increase no. of days to increase 2 power in the expression to make us large sum of money
    and it is given that no. of days is not the issue as well


    and we have to just find out the no. set bits of this no. and sum of set bits = no. of set bits as set bit has only value of 1
    because 
        5 = 101 = 2^2 * 1  + 2^1 * 0  +  2^0 * 1


*/                                                                  

// int main() {

//     int t;
//     cin>>t;
//     while (t--)
//     {
//         long long x;
//         cin>>x;
//         cout<<__builtin_popcountll(x)<<"\n";
//     }
    

//     return 0;
// }















// *******Next Question


// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/xor-challenge-2420f189/



/*
A^B = C
C is given and we need to find A and B such that their product is maximum
for maximising their product I need to maximize A and B as well thus if 0 bit comes in C I will chose case of 1 1 for A and B
and in case of 1 bit then any one of A and B can have 1bit and another can have 0 bit
XOR operation
1 1 -> 0    1 0 -> 1
0 0 -> 0    0 1 -> 1

let's assume C = 1 1 0 1 0 1 0 1 1 0 1 1
             A =     1   1   1     1        
             B =     1   1   1     1


no. of bits in a given decimal number n is log(n)
 i.e. in 5 no. of bits = log(5) ~ 3


Given range of C is < 10^5 -> log(10^5) ~ 16 bits




We have 2^16 possible cases as for every bit of C, we have two choices
and we can compute every case





*/






int main(){
    int c;
    cin>>c;
    int bit_ct = (int)log2(c) + 1;  // this is how we find bit count of any number
    int a = 0, b = 0;
    vector<int> set_bits;
    for (int i = 0; i < bit_ct; i++)
    {
        if(c & (1<<i)){
            //set bit
            set_bits.push_back(i);
        }else{
            a |= (1<<i);
            b |= (1<<i);
        }
    }
    // subset generation using mask
    long long ans = -1;
    int sz = 1<<set_bits.size();
    for (int mask = 0; mask < sz; mask++)
    {
        int a_copy = a, b_copy = b;
        for (int j = 0; j < set_bits.size(); j++)
        {
            if(mask & (1<<j)){
                a_copy |= (1<<set_bits[j]);
            }else{
                b_copy |= (1<<set_bits[j]);
            }
        }
        ans = max(ans, a_copy*1LL*b_copy);
    }
    cout<<ans<<endl;

}