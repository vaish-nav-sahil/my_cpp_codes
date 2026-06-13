// 22. Generate Parentheses
// link -> https://leetcode.com/problems/generate-parentheses/description/

#include<bits/stdc++.h>
using namespace std; 

// class Solution {
// private:
//     vector<string> result;
// public:
//     bool isValid(string& curr){
//         int count = 0 ;
//         for (char ch : curr){
//             if (ch =='(') count++;    //if open bracket found then add 1 
//             else count--;             //else add -1
//             if (count <0) return false;   //at any moment if value of count goes -ve then there is a imbalance indicating a invalid parenthesis

//         }
//         return count==0;
//     }

//     void solve(string& curr,int n){
//         if (curr.length() == 2*n){                 //base case 
//             if (isValid(curr)){                    
//                 result.push_back(curr);            //add valid parenthesis to result
//             }
//             return ;
//         }
//         curr.push_back('(');                     //option 1 push open bracket
//         solve(curr,n);                           //leap of faith -> recursion will do its job 
//         curr.pop_back();                         //remove that open bracket 
//         curr.push_back(')');                     //and explore closed bracket
//         solve(curr,n);                           //leap of faith -> recursion will again do the job 
//         curr.pop_back();                         
//     }
//     vector<string> generateParenthesis(int n) {
//         string curr = "";
        
//         solve(curr,n);

//         return result;
        
//     }
// };



//BETTER APPROACH -> 
class Solution {

private: 
    vector<string>result;

public:

    void solve(string curr , int n,int open ,int close){

        if (curr.length() == 2*n){
            result.push_back(curr); //not need to check for valid now as a earlier check is already added.
        }

        if (open < n){    //if open bracket increases or equlas n then there is a imbalance or invalid parenthesis so no need to explore that option
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
        }
        
        if (close<open){   //if closed bracket increases  open bracket  then there is a imbalance or invalid parenthesis so no need to explore that option too
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {

        string curr = "";
        int open = 0,close = 0;

        solve(curr,n,open,close);

        return result;
    }
};

int main (){
    int n;
    cin>>n;

    Solution obj;
    vector<string>ans = obj.generateParenthesis(n);

    for(string str : ans){
        for(char ch : str){
            cout<<ch<<" ";
        }
        cout <<endl;
    }
    return 0;
}






