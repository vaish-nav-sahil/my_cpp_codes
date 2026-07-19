// 1081. Smallest Subsequence of Distinct Characters
// http://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/?envType=daily-question&envId=2026-07-19

// 316. Remove Duplicate Letters(same question)
// https://leetcode.com/problems/remove-duplicate-letters/description/

#include<bits/stdc++.h>
using namespace std ;

// question says we need to remove all the duplicate letters and try to make the resutlant string lexicographically smallest of all possible subsequences 

//Apprroach 1 -> (Using a simple story)

// Story -> 
// Make a empty "ans" string which will store the lexicographically smallest subsequence and couple of two 26 sized vector one with int datatype and other one as boolean datatype .
//Point of having "last_occurence vector" is store the last most occurence of any character so that during checking we are assured that after an index i there is same character occuring in future for including it in "ans"
//Point of having "taken" vector is to store whether the character is already taken in "ans" string or not 
//Fill the "last occurence vector" in one go 
//story is simple include a character from string then check if that string is lexicographically a smaller then we will check previous characters and pop it from "ans" string until either the string becomes empty or the previous characrter becomes lesser than current string 
//And if the character is greater character than previous charcter then continue no need to do anything mark that it "taken" as true and push_back in "ans" string .

// t.c-> O(n)      We visit each character only once (Note that an element once popped from result is never put back) NOTE : In this Qn,                I have used the result string which is working just like a stack.
                   // We push into it, we pop from it from the back (result.pop_back()). So this Qn also falls under stack category.
                   // You can also solve it using stack.
// s.c-> O(k);     k -> k is size of ans string 
 
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans ="";
        vector<int>last_occurence(26,0);
        vector<bool>taken(26,false);

        for(int i =0;i<s.size();i++){
            int index = s[i] - 'a';
            last_occurence[index]=i;
        }
        
        
        for(int i = 0 ;i <s.size();++i){
            char ch = s[i];
            int index = ch - 'a';
            if (taken[index] == true)  continue;
            while(ans.size()>0 && ans.back() > ch && last_occurence[ans.back()-'a'] > i ){
                taken[ans.back()-'a'] = false;
                ans.pop_back();
            }          
            ans.push_back(ch);
            taken[index] =true; 
        }
        return ans;
    }
};

//Approach-2 (Using stack)
//T.C : O(n) - We visit each character only once (Note that an element once popped from result is never put back
//            (Using  Monotonic stack -> a stack having increasing or decreasing order or any other specific order in stack )
//S.C : O(n)  stack

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<char> st;
        
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            lastIndex[ch-'a'] = i;
        }
        
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(taken[idx] == true) continue;
            while(!st.empty()  && s[i] < st.top() && lastIndex[st.top() - 'a'] > i) {
                taken[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            taken[idx] = true;
        }
        
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(begin(result), end(result));
        return result;
    }
};

int main(){

    return 0;
}
