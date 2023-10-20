#include <bits/stdc++.h>
using namespace std;
// NEXT GREATER ELEMENT

/*
given array =  4  5  2  25  7  8
NGE         =  5 25 25  -1  8 -1
in nge array we will store index instead of value


using for loop we can do this in n^2 
but using stack we can do this in O(n)

Many people usually get confused seeing the 2 loops in the code and think it is not O(N) but it is O(N) only, See it this Way, The time complexity will be equal to total amount of push and pop operations in the stack. Now each element in the vector will get pushed into the stack once and will get pop out of the stack also once, hence total of 2N operations will be there. hence time complexity is O(N).
*/

vector<int> NGE(vector<int> v){
    vector<int> nge(v.size());
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i]>v[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }

    return nge;
    
}


int main() {

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    /*
    6
    4 5 2 25 7 8
    */
    vector<int> nge = NGE(v);
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" "<<(nge[i] == -1 ? -1: v[nge[i]])<<endl;
    }
    

    return 0;
}