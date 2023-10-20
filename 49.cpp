#include <bits/stdc++.h>
using namespace std;
// 6 Amazing BIT Manipulation Ticks You must Know


void printBinary(int num){
    for (int i = 10; i >= 0; i--)
    {   
        cout<< ((num>>i) & 1);       
    }
    cout<<endl;
}



// // checking even or odd
// int main() {

//     for (int i = 0; i < 8; i++)
//     {
//         printBinary(i);
//         /*
//             n&1 ==  1 then odd
//             n&1 == 0 then even

//             n&1 is faster than n%2==0    
//             compared to bit manipulation % and / are considered to be slow
//         */
//         if(i & 1){      
//             cout<<"odd\n";
//         }else{
//             cout<<"even\n";
//         }
//     }
    

//     return 0;
// }


// // multiply divide by 2
// int main() {

//     int n = 5;
//     cout<<(n>>1)<<endl;   //n>>1 = n/2 divides n by 2    n>>1 is fast than n/2
//     cout<<(n<<1)<<endl;   //n<<1 = n*2  multiples n by 2

//     // 101 -> (2^2*1 + 2^1*0 + 2^0*1)/2 = 2^1*1 + 2^0*1  
//     // 101 -> (2^2*1 + 2^1*0 + 2^0*1)*2 = 2^3*1 + 2^2*0 + 2^1*1   
//     // 10 -> 2*1 + 2^0*0
//     // 1010 -> 2^3*1 + 2^2*0 + 2^1*1 + 2^0*0

//     return 0;
// }




// // Uppercase and lowercase conversion
// int main(){
//     for (char c = 'A'; c <= 'E'; ++c)
//     {   
//         cout<<c<<" "<<(int)c<<" ";
//         printBinary((int)c);
//     }
//     for (char c = 'a'; c <= 'e'; ++c)
//     {   
//         cout<<c<<" "<<(int)c<<" ";
//         printBinary((int)c);
//     }
//     /*
//      difference btw A and a binary is that 5th bit is set in a and it is unset in A
//      00001000001 - A
//      00001100001 - a
//     */
    
//     char A = 'A';
//     char a = A | (1<<5);
//     cout<<a<<endl;
//     cout<<(char)( a & (~(1<<5)));

//     cout<<(char)(1<<5)<<endl; //1<<5 is ascii value of ' '
//     // there is no char regarding ~(1<<5) this number is very large value
//     // and ascii value are only from 0 to 255

//     cout<<(char)('C' | ' ')<<endl;

//     // c-> 00001100011
//     //     11111011111 &   -- but this value ka char is not possible
//     //    -------------

//     // c-> 00001100011
//     //     00001011111 &   -- but this binary char is possible which is '_' 
//     //    -------------
//     // this will also work 

//     cout<<(char)('c' & '_')<<endl;  



//     // conclusion

//     // uppercase to lowercase
//     char B = 'B';
//     char b= 'B' | ' ';
//     cout<<b<<endl;
//     // lowercase to uppercase
//     char d = 'd';
//     char D = d & '_';
//     cout<<D<<endl;

// }






//Clear LSB
// int main(){
//     printBinary(59);
//     //00000111011
//     // we have to unset all bits upto ith bit
//     // 1. we can do it by applying loop
//     // 2. in one shot

//     /*
//     00000111011
//     11111100000 &
//     -----------------
//     this is how we unset the bits

//     11111100000 this is inverted version of 00000011111
//     and 00000011111 this can be achieved through 00000100000 - 1 = 1<<5 - 1
//     thus i<<5 - 1 for unsetting 5 bits
//     */


//    int a = 59;
//    int i = 4; //index
//    int b = a & (~((1<<(i+1)) - 1));
//    printBinary(b); //00000100000
// }







//Clear MSB
// int main(){
//     printBinary(59);
//     //00000111011
//     // we have to unset all bits upto ith bit
//     // 1. we can do it by applying loop
//     // 2. in one shot

//     /*
//     00000111011
//     00000001111 &
//     -----------------
//     this is how we unset the bits

//     and 00000001111 this can be achieved through 00000010000 - 1 = 1<<4 - 1
//     thus i<<4 - 1 for unsetting bits upto 4ith bit from msb
//     */


//    int a = 59;
//    int i = 4; 
//    int b = a & ((1<<(i)) - 1);
//    printBinary(b); //00000001011
// }








// Check power of 2
int main(){
    int n = 64;
    //n & (n-1) != 0 then not power of 2 
    //n & (n-1) == 0 then power of 2 
    /*
        if power of 2 then binary would be like  100000
        and then  - 1 of that would be like      011111 &
                                                --------
                                                 000000
    */
    if(n & (n-1)){
        cout<<"not power of 2";
    }else{
        cout<<"power of 2";
    }
}
