// 3517. Smallest Palindromic Rearrangement I
// link -> https://leetcode.com/problems/smallest-palindromic-rearrangement-i/?envType=daily-question&envId=2026-07-28

#include<bits/stdc++.h>
using namespace std;

//Approach -> 
// 1. Take half of s and sort it.
// 2. Now add the starting part of sorted s to the end of s sequentially.

// t.c -> O(n+logn)
// s.c -> O(1)

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int mid =n/2;
      
        sort(begin(s),begin(s)+mid);

        for(int i=0;i<mid;++i){
            s[n-1-i] = s[i];
        }
        return s;
    }
};

int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.smallestPalindrome(s);
    return 0;
}
