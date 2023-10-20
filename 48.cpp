#include <bits/stdc++.h>
using namespace std;
// PLAYING WITH BITS | Set, Unset, Count Bits

/*
    10111011
           ^this is the lsb (least significant bit), i.e right most bit is the lsb
    l      r  binary no. indexing is done from right to left    
    76543210 this is the bit no.

    0th bit is the - least significant bit (LSB)
    nth bit is the - most significant bit (MSB)

    -> bit is called set if its value is 1
    -> bit is called unset if its value is 0

    in the above given binary number 6bits are set and 2 bits are unset



    ###
    Now to check that ith bit is set or not -> what we will do is take a binary which has only ith bit set and all other are unset and then take & of this binary with the given binary
    lets we want to check 1 bit is set or unset in 101
    we will take 010

    Now 101
        010 &
       -------
    this will give 000 thus we will know that 1st bit of the given binary is unset
    thus if a zero no. is returned then the given binary has ith bit unset
    and if non zero no. is returned then the given binary has ith bit set 

    To generate ith bit set and all other to be unset = 1<<i
    1<<0 -> 1 = 01
    1<<1 -> 10 = 010
    1<<2 -> 100 = 0100
    1<<3 -> 1000 = 01000

    ###
    If we subtract 100 - 1 = 11 = 2^2 - 1 = 3
                   1000 - 1 = 111 = 2^3 - 1 = 7
                   100000 - 1 = 11111 = 2^5 - 1 = 31
    
    and all these 111 type of number are 2^length - 1


    ###
    bit set and unset

    make ith bit set
        10101
        00010 or    (1<<1) ~ (1<<i) ith bit ko set karna hai
        ------
        10111

    make ith bit unset
        10101
        11011 &          -> this is inverted form of 00100    = ~(1<<i)
        -------
        10001

    ~(00100) = 11011 (this is called tilda of 00100 is 11011)


    ###
    bit toggle

    10101
    00010 ^  XOR with 1<<1
    ------
    10111


    ###
    finding count of set and unset bits

*/


void printBinary(int num){
    for (int i = 10; i >= 0; i--)
    {   
        cout<< ((num>>i) & 1);       // num>>i this brings ith bit to 0th bit becuase before ith index we have i no.
    }                                      // 10101>>2 -> 1010 -> 101
    cout<<endl;                            //  101 & 1 -> 1 and 100 & 1 -> 0
}

int main() {

    int a = 13;
    printBinary(a); //00000001101

    int i = 3;
    // check bit is set or unset
    if((a & (1<<i)) != 0){
        cout<<"set bit\n";
    }else{
        cout<<"not set bit\n";
    }

    //bit set
    printBinary(a | (1<<1));

    //bit unset
    printBinary(a & (~(1<<3)));

    //toggle
    printBinary(a ^ (1<<2));
    printBinary(a ^ (1<<3));

    //count
    int ct = 0; //count of set bit
    for (int i = 31; i >= 0; --i)
    {
        if( (a & (1<<i)) != 0){
            ct++;
        }
    }
    cout<<ct<<endl;



    // in_built function for counting set bits
    cout<<__builtin_popcount(a)<<endl;       // this only works for int values
    cout<<__builtin_popcountll(1LL<<35)<<endl; 
    

    return 0;
}