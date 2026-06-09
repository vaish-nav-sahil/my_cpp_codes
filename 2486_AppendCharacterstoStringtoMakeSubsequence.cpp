// 2486. Append Characters to String to Make Subsequence
// link -> https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/

// t.c -> O(m); here m is size of string s(precisely)
// s.c -> O(1);

// Approach:
// Use two pointers to match characters of t in order within s.
// Traverse s once; whenever s[i] == t[j], advance both pointers.
// After processing s, j represents the number of matched characters.
// Remaining characters (t.size() - j) must be appended.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.size(),n = t.size();
        int i = 0 ,j = 0;
        int added = t.size();
        while(i<m ){             //run it until s is not finished as soon as s in finished there's gonna no chance of any kind of matching
            if (s[i] == t[j]){    //match 
                added--;          //reduce number to be added 
                i++,j++;          //increase both pointer for match,not interrupting the order
            } 
            else{                 //mismatch
                i++;              //update i for checking any future matching in s with t
            }
        }
        return added;
    }
};

int main(){
    string s,t;
    cin>>s,t;
    
    Solution obj;
    int ans = obj.appendCharacters(s,t);
    cout<<ans;
    return 0;   
}
