#include <bits/stdc++.h>
using namespace std;
// Knapsack Concept and Variations: Dynamic Programming

/*
Knapsack - Concept
- Various Problems
- 0/1 Knapsack
- Subset Sum
- Rod Cutting
*/


/*
weights -   2       1        3        6       4
price  -    5       15       20       60      30

but thief can have max weight of 10 and he want to maximize the price

so for, weight 4 we have two options - choosed or not choosed 
    then for weight 6 again we have two options - choosed or not choosed
    .
    .
    this is how knapsack works

    this is called 0/1 knapsack - means you can either take or not take it, you can't take half of it nor you can' take any fraction of it
        and also you can take the item once only





## Unbounded knapsack

we have a rod of length of 5 (Rod Cutting Problem)

and for cutting rod of length 1 I will get 3 rupees from customer
                              

i.e.    1   2   3   4 - Length
        3   2   1   4 - Price

how to earn maximum money
- here the difference is we can repeat items i.e. we can sell length 1 rod multiple times to get more profit

This is called Unbounded Knapsack - there is no limit on using the amount of item


These are two types of knapsack problems

There is also fractional knapsack in which we can select a fraction of a item, this is not dp actually, this is solved using greedy approach
*/

/*
    2   3   5   6   7
    does any subset of this array can have sum = 12

    2 3 7

    how to solve this
    include 7 or not
    then for 6 we have to make sum 5 or for 6 we have to make sum 12
    .
    .
    .

    based on some condition we can either select or not select the item this is called knapsack problems

*/

int main() {

    

    return 0;
}