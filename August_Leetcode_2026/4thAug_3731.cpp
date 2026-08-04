// 3731. Find Missing Elements
// link -> https://leetcode.com/problems/find-missing-elements/description/?envType=daily-question&envId=2026-08-04

#include<bits/stdc++.h>
using namespace std;

// Approach -> 
// 1. find max and min by iterating 
// 2. sort the original array 
// 3 . then iterate in original array and check for missing number from min to max of array 
// t.c -> O(n + log n + n)
// s.c - > O (n) 

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>result;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto it : nums){
            if (it > maxi ) maxi = it;
            if (it < mini ) mini = it ;
        }

        sort(begin(nums) , end(nums));

        int j=1;
        for(int i = mini+1 ;i < maxi; i++){
            if (j<nums.size() && nums[j] == i) {
                j++;
                continue;
            }
            else {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main(){
    int n ; 
    cin >> n;
    
    vector<int>arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    Solution obj;
    vector<int>ans = obj.findMissingElements(arr);

    for(auto it : ans) cout<<it<<" " ;

    return 0;
}