// 486. Predict the Winner
// link -> https://leetcode.com/problems/predict-the-winner/description/?envType=daily-question&envId=2026-08-01

#include<bits/stdc++.h>
using namespace std;

//Approach -> (Optimal game strategy / min max game )
        //   {
        //     "When it's your turn 
        //     -> do your best (max)
        //     when it's your opponent turn 
        //     -> expect the worst from result (min)"
        //   }


// Recursion-> 
class Solution {
public:
    int solve(int i ,int j ,vector<int>& nums){
        if (i > j ) return 0;   //exhausted 

        if (i == j ) return nums[i];   //land on same number then return number as choice 

        int take_i = nums[i] + min(solve(i+2,j,nums) , solve(i+1,j-1,nums)); //expect min from choice as opponent took max that's why min used

        int take_j = nums[j] + min(solve(i+1,j-1,nums),solve(i,j-2,nums));//expect min from choice as opponent took max that's why min used


        return max(take_i,take_j);      //take max from what you get to win
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        int total_score = accumulate(begin(nums),end(nums),0);    //total score

        int p1_score=solve(0,n-1,nums);     //gets total score for p1 from recursion 

        int p2_score= total_score - p1_score;     //total -p1's score

        return p1_score>=p2_score;            
 

    }
};

//Memoization -> 
class Solution {
public:
    int t[23][23]; //2d array
    int solve(int i ,int j ,vector<int>& nums){
        if (i > j ) return 0;

        if (i == j ) return nums[i];

        if (t[i][j] != -1) return t[i][j];  //already filled the value of overlapping subproblem 

        int take_i = nums[i] + min(solve(i+2,j,nums) , solve(i+1,j-1,nums));

        int take_j = nums[j] + min(solve(i+1,j-1,nums),solve(i,j-2,nums));

        return t[i][j]=max(take_i,take_j);  //return by saving the value in 2d array
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n = nums.size();

        int total_score = accumulate(begin(nums),end(nums),0);

        int p1_score=solve(0,n-1,nums);

        int p2_score= total_score - p1_score;

        return p1_score>=p2_score;


    }
};

int main(){

    return 0;
}