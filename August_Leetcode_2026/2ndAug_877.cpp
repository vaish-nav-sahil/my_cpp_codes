#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , vector<int>& piles){
        if (i>j) return 0;

        if (i==j) return piles[i];

        if (dp[i][j] != -1) return dp[i][j];

        int take_i = piles[i] + min(solve(i+2 , j , piles ) , solve(i+1,j-1,piles));

        int take_j = piles[j] + min(solve(i+1 ,  j-1 ,piles) , solve(i,j-2,piles) );

        return dp[i][j] = max(take_i, take_j);
        }
    bool stoneGame(vector<int>& piles) {

        memset(dp,-1,sizeof(dp));

        int n = piles.size();

        int total = accumulate(begin(piles),end(piles),0);

        int a_score = solve(0,n-1,piles);

        int b_score = total-a_score;

        return a_score>b_score;
    }
};

int main(){

    return 0;
}