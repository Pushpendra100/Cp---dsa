#include <bits/stdc++.h>
using namespace std;
// Binary Numbers and Bits Basics

/*
    0 - 0
    1 - 1
    2 - 10
    3 - 11
    4 - 100
    5 - 101
    6 - 110
    7 - 111 -> to convert in decimal 1*2^2 + 1*2^1 + 1*2^0 = 7

    * so you can notice odd no. ends with 1 while even no. ends with 0

    * Operators
                 &       |       ^
                AND     OR      XOR
    0   0       0       0       0
    0   1       0       1       1
    1   0       0       1       1
    1   1       1       1       0

    * XOR of two same things is 0 while of two different things is 1

    * NOT operator (!)
        1 -> 0
        0 -> 1
    
    * Left shift operator -> <<
        3<<1 (3 left shift 1) it means one left shift the binary of 3 and then gives the decimal number
        i.e. 11 -> 110
        3<<2 (3 left shift 2) it means two left shift the binary of 3
        i.e. 11 -> 1100

    * Right shift operator -> >>
        3>>1 (3 right shift 1) it means remove last element from binary of 3
        i.e. 11 -> 1
        6>>1
        110 -> 11 -> 3
        6>>2
        110 -> 1 -> 1


    * if there is 4 bit number
        then 2 * 2 * 2 * 2   ( 2 options per seat)
        thus  = 2^4 = 16 numbers will be there

        0000 -> 0
        0001 -> 1
        0010 -> 2
        ... .
        1111 -> 15

        thus max number is 2^4 - 1 = 15 from using 4 bits


    * int is 32 bit numbers it means we can store 32 bits
        thus max value stored in int is 2^32 - 1

    * 1<<0 - 1  - 1
      1<<1 - 10 - 2
      1<<2 - 100 - 4
      1<<3 - 1000 - 8
                  - 16
                  - 32
                  - 64
        
        thus we can say that 1<<n = 2^n


*/

const int N = 1e5+10;

int main() {

    // cout<<INT_MAX<<endl;  //2147483647
    // cout<<(1<<2)<<endl;

    //this will give overflow warning
    // int a = (1<<32) - 1;  //maybe you can store (1<<32) -1 but 1<<32 will have 33 bits and thus this can't be stored in int while calculating

    //this will not give overflow warning
    // int a = (1LL<<32) - 1; // this makes 1 long long while calculating 1LL<<32
    // cout<<a<<endl; // -1, means overflowed

    int b = (1LL<<31) - 1; 
    cout<<b<<endl; //2147483647

    // this means int is signed integer thus last bit is used for containing sign
    // if 0 -> then positive number
    // if 1 -> then negative number


    unsigned int c = (1LL<<32) - 1;  //unsigned int stores no. in all 32 bits 
    cout<<c<<endl; //4294967295

    // thus int range is from - ((2^31)-1) to ((2^31)-1)
    // while unsigned int range from 0 to ((2^32)-1) which is double of positive range of int


    return 0;
}