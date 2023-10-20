#include <bits/stdc++.h>
using namespace std;
// BALANCED BRACKETS MATCHING

/*
    ((())) -> balanced
    ((()  -> unbalanced
    [[()]](() -> unbalanced
*/

unordered_map<char,int> symbols = {
    {'[', -1},
    {'{', -2},
    {'(', -3},
    {']', 1},
    {'}', 2},
    {')', 3},
};

string isBalanced(string s){
    stack<char> st;
    for (char &bracket : s)
    {
        if(symbols[bracket]<0){
            //opening bracket
            st.push(bracket);

        }else{
            //closing bracket
            if(st.empty()) return "NO";
            char top = st.top();
            st.pop();
            if(symbols[top]+ symbols[bracket] != 0){
                return "NO";
            }
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}


int main() {

    // we will put opeing brackets in the stack and check the stack for the opening bracket for the closing bracket

    /*
    input
    3
    {[()]}
    {[(])}
    {{[[(())]]}}
    */


    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        cout<<isBalanced(s)<<"\n";
    }


    

    return 0;
}