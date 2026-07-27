// 1464. Maximum Product of Two Elements in an Array
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2026-07-27

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        return (nums[0]-1)*(nums[1]-1);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    Solution obj;
    cout<<obj.maxProduct(arr);
    return 0;
}
