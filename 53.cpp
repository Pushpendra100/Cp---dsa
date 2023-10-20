#include <bits/stdc++.h>
using namespace std;
// GCD and LCM using Euclid's Algorithm With Applications
// GCD - greatest common divisor (HCF - highest common factor)
// LCM - least common multiple

/*
    4 and 12 -> GCD = 4
    we write prime factorization for each and
        4 = 2^2 * 3^0
        12 = 2^2 * 3^1
        for GCD extract min. powers
            thus 2^2*3^0 = 4
        for LCM extract max. powers
            thus 2^2 * 3^1 = 12

    similarly for 12 and 18
    12 = 2^2 * 3^1
    18 = 2^1 * 3^2
        GCD = 2^1 * 3^1 = 6
        LCM = 2^2 * 3^2 = 36

    ****** Relationship b/w GCD and LCM
    (a * b)/GCD = LCM

    ex. for 12 and 18

    2^2 * 2^1 * 3^1* 3^2
    ---------------------  = 2^2 * 3^1 
        2^1 * 3^1

    thus if we get GCD then we can give LCM in O(1) time



    ### Euclid's algorithm

    lets start with 4 and 12 only
     divide 12 with 4 until remainder is 0 at that point the divisor is GCD
    i.e. long division this is only euclid's algorithm

        3
       ______
    4 |  12
         12
       ------
        0
    thus GCD is 4


    for 12 and 18

        1
        ______
    12 |  18
          12    2
        ----- _______
           6 |  12 
                12
               ---- _____
                0  |  6

    thus GCD is 6 


    in case we divide 12 with 18
    thus only step extra added before


        0 
        ___
    18 | 12
          0     1
        ---- ______
         12 |  18
               12    2
            ----- _______
                6 |  12 
                    12
                    ---- _____
                    0  |  6

*/


int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
// time complexity is less than O(log(n))


int main() {

    cout<<gcd(4, 12)<<endl;
    cout<<gcd(12, 4)<<endl;
    cout<<gcd(12, 0)<<endl;
    cout<<gcd(12, 1)<<endl;
    cout<<gcd(12, 18)<<endl;
    cout<<12 * 18 / gcd(12, 18)<<endl;

    // in built function for gcd    
    cout<<__gcd(12, 18)<<endl; //O(log(n))
    // for three numbers gcd
    // gcd(gcd(a,b),c)


    //To find the minimum fraciton
    /*
        12    6     2
        -- = --- = ---
        18    9     3

        so simple  12/GCD(12, 18)        12/6      2
                  ----------------  =   ------  = ---
                   18/GCD(12, 18)        18/6      3
    */



   // also,
//    gcd(a, b) == gcd(b, a%b) provided b is non zero otherwise a%b is not defined
    cout<<gcd(12, 5)<<endl;
    cout<<gcd(5, 2)<<endl;
    return 0;
}