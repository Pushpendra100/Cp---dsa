#include <bits/stdc++.h>
using namespace std;
// Inclusion Exclusion Explained
// https://www.hackerearth.com/problem/algorithm/the-three-musketeers-6efd5f2d/

/*
    A∪B = A + B - A∩B
    A∪B∪C = A + B + C - A∩B - B∩C - C∩A + A∩B∩C
    thus + - + - sign goes on alternatively
*/


/*
if n names have vowel e
                                         n(n-1)(n-2)
then we can select three people is nC3 = -------------
                                            6

but we have to keep one thing in mind
eba, eca, eda -> we have three strings
for e: 3C3 = 1
for a: 3C3 = 1
---------------
             2
but answer is 1

so count[e] + count[a] - count[e∩a]


in this question we have 5 vowels thus
we need to find  a∪e∪i∪o∪u

*/


/*
input
2
5
helen
irena
arthos
pentos
tulu
3
alen
bira
cult

output  
1
0
*/


bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';    
}

// subset generation
vector<string> subsets(string s){
    int sz = (1<<s.size());
    vector<string> ans;
    for (int mask = 0; mask < sz; mask++)
    {
        string subset;
        for (int bit = 0; bit < s.size(); bit++)
        {
            if(mask & (1<<bit)) {
                subset.push_back(s[bit]);
            }
        }
        if(subset.size()){
            ans.push_back(subset);
        }
    }
    return ans;
}

int main() {

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        string str[n];
        for (int i = 0; i < n; i++)
        {
            cin>>str[i];
        }
        unordered_map<string, int> hsh;
        for (int i = 0; i < n; i++)
        {
            set<char> distinct_vw;
            for (char ch : str[i])
            {
                if(isVowel(ch)){
                    distinct_vw.insert(ch);
                }
            }
            string vowel_str;
            for (char ch : distinct_vw)
            {
                vowel_str.push_back(ch);
            }
            vector<string> all_subsets = subsets(vowel_str);
            for (string vowel_subset : all_subsets)
            {
                hsh[vowel_subset]++;
            }
        }
        long long ans = 0;
        for (auto &pr : hsh)
        {
            if(pr.second < 3) continue;
            long long ct = pr.second;
            long long ways = ct * (ct-1) * (ct-2) / 6;
            if(pr.first.size() % 2 == 0){
                ans -= ways;
            }else{
                ans += ways;
            }
        }
        cout<<ans<<endl;
        
    }
    
    

    return 0;
}