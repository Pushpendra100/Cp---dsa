#include <bits/stdc++.h>
using namespace std;
// Generate Parenthesis: Advanced Recursion and Backtracking
// https://leetcode.com/problems/generate-parentheses/description/


vector<string> valid;

// as we are going deep in recursion and getting back then we need to undo our changes thus pop back is used and this is only called backtracking
// string also pass by value and thus take O(n) time extra, thus make it mass by reference
void generate(string &s, int open, int close){

    if(open == 0 && close == 0){
        valid.push_back(s);
        return;
    }

    if(open>0){
        s.push_back('(');
        generate(s, open -1, close);
        s.pop_back();
    }

    if(close>0){
        if(open < close){   // i.e. in string open brackets are more than close
            s.push_back(')');
            generate(s, open, close -1);
            s.pop_back();
        }
    }
}
// time complexity in recursion - 
// 1. function call kitni bar hua
// 2. and function ki time complexity kitni hai


// so yahan par 
// ek function toh O(1) time complexity ka hai, kyunki koi bhi loop nahi chal raha and saare operation O(1) ke hain
// and ab har ek function mein worst case hai do bar genearte function chale
/*
          O             -> 2^0
      O       O         -> 2^1
    O   O   O   O       -> 2^2
                        -> 2^n
                
    2^0 + 2^1 + 2^2 + 2^3 .... + 2^n  this is gp
     = 2*(2^n - 1) = 2^n+1 ~ 2^n

    here in this question this n will be 2n of the question
    thus time complexity O(2^2n) ~ O(2^n)
*/


int main() {

    int n;
    cin>>n;
    string s;
    generate(s, n, n);

    for (auto &value : valid)
    {
        cout<<value<<endl;
    }
    
    

    return 0;
}