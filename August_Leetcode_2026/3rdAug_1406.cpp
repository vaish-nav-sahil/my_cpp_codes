// 1406. Stone Game III
// link -> https://leetcode.com/problems/stone-game-iii/?envType=daily-question&envId=2026-08-03

#include<bits/stdc++.h>
using namespace std;

//Approach -> Recursion (160 / 185 testcases passed)
// try to build a recursuion tree and see how crystal clear problem becomes

// Time Complexity: O(3^n)
// Space Complexity: O(n)
class Solution {
public:
    int n;

    int solve(vector<int>& stoneValue,int i){
        if ( i >= n ) return 0;       //array exhausted

        int ans = stoneValue[i] - solve(stoneValue,i+1);     //took only 1 stone and rest left for bob to choose

        if (i+1<n) ans =  max(ans,stoneValue[i]+stoneValue[i+1] - solve(stoneValue,i+2)); //took  only 2 stone and rest left for bob to choose
        //also collect max from existing value and value of ans 

        if (i+2 < n ) ans =  max(ans,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(stoneValue,i+3));  //took  all 3 stone and rest left for bob to choose
        //also collect max from existing value and value of ans 

        return ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        int difference = solve(stoneValue,0);          //Alice_score - bob_score

        if (difference > 0 ) return "Alice";

        else if (difference < 0 ) return "Bob";

        else return "Tie";

    }
};

//Approach -> Memoization
//what we changed was to introduce a dp (1d)array of size n+1 to store overlapping subproblems and since there is only one changing parameter i.e i 

// Time Complexity: O(n)
// Space Complexity: O(n + n)

class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& stoneValue,int i){
        if ( i >= n ) return 0;       //array exhausted

        if (dp[i] != -1) return dp[i];
        int ans = stoneValue[i] - solve(stoneValue,i+1);     //took only 1 stone and rest left for bob to choose

        if (i+1<n) ans =  max(ans,stoneValue[i]+stoneValue[i+1] - solve(stoneValue,i+2)); //took  only 2 stone and rest left for bob to choose
        //also collect max from existing value and value of ans 

        if (i+2 < n ) ans =  max(ans,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(stoneValue,i+3));  //took  all 3 stone and rest left for bob to choose
        //also collect max from existing value and value of ans 

        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        dp.resize(n+1,-1);

        int difference = solve(stoneValue,0);          //Alice_score - bob_score

        if (difference > 0 ) return "Alice";

        else if (difference < 0 ) return "Bob";

        else return "Tie";

    }
};

//Bottom up (Tabulation)

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int n;
    vector<int>dp;
    int solve(vector<int>& stoneValue,int i){
        if ( i >= n ) return 0;       //array exhausted

        if (dp[i] != -1) return dp[i];
        int ans = stoneValue[i] - solve(stoneValue,i+1);     //took only 1 stone and rest left for bob to choose

        if (i+1<n) ans =  max(ans,stoneValue[i]+stoneValue[i+1] - solve(stoneValue,i+2)); //took  only 2 stone and rest left for bob to choose
        //also collect max from existing value and value of ans 

        if (i+2 < n ) ans =  max(ans,stoneValue[i]+stoneValue[i+1]+stoneValue[i+2] - solve(stoneValue,i+3));  //took  all 3 stone and rest left for bob to choose
        //also collect max from existing value and value of ans 

        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();

        dp.resize(n+1,-1);

        int difference = solve(stoneValue,0);          //Alice_score - bob_score

        if (difference > 0 ) return "Alice";

        else if (difference < 0 ) return "Bob";

        else return "Tie";

    }
};

int main(){

    return 0;
}