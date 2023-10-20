#include <bits/stdc++.h>
using namespace std;

/*
    stack - balanced paranthesis (({}))[()]
        - Next Greater Element NGE

    queue - bfs (breadth first search)
        - its use comes mainly in graphs


    Operations in stack (LIFO) :-
        1. push - pushes element to top
        2. pop - remove element to top
        3. top - shows element at top

    Operations in queue (FIFO) :- 
        1. push - pushes element at end
        2. pop - remove element at front
        3. front - shows element at front

*/

int main() {

    // stack<int> s;
    // s.push(2);
    // s.push(3);
    // s.push(5);
    // s.push(9);

    // while (!s.empty())
    // {
    //     cout<<s.top()<<endl;
    //     s.pop();
    // }


    queue<string> q;
    q.push("abc");
    q.push("bcd");
    q.push("cde");
    q.push("def");
    
    while(!q.empty()){
        cout<<q.front()<<"\n";
        q.pop();
    }

    

    return 0;
}