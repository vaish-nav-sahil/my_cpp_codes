// 3867. Sum of GCD of Formed Pairs
// link -> https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// t.c -> O(n + log n + n/2)   or O(n long n)
// s.c -> O(n)
//Task to be performed  ->
// 1. Construct prefix gcd
// 2. sort prefixgcd in increasing order
// 3. Form pairs by taking the smallest unpaired element and the largest unpaired element. 
// 4. repeat until no pairs left
// 5. For each formed pair, compute the gcd of the two elements.
// NOTE -> If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
// 6. Return an integer denoting the sum of the GCD values of all formed pairs.

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int>prefixGCD;
        for(int i = 0 ; i < n ;++i){
            if (maxi < nums[i]) maxi = nums[i];

            prefixGCD.push_back(__gcd(maxi,nums[i]));
        }
        sort(prefixGCD.begin(),prefixGCD.end());
        int i=0,j=n-1;
        long long sum=0;
        while(i<j){
            sum += __gcd(prefixGCD[i],prefixGCD[j]);
            i++,j--;
        }                     // here we have not repeated the operations as question said but i am providing it below .
        return sum;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    Solution obj ;
    cout<<obj.gcdSum(arr);
    return 0;
}
