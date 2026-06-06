// better approach
// t.c - > O(3n) 
// s.c - > O(3n)

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);
        vector<int>answer(n,0);
        int sum = accumulate(nums.begin(),nums.end(),0);
        int r_sum = sum , l_sum =0;
        for(int i = 0 ;i<n;++i){
            if (i==0){
                rightSum[i] = r_sum - nums[i];
                r_sum -=nums[i];
            } 
            else if (i==n-1) {
                leftSum[i] = l_sum + nums[i-1];    
            }
            else{
                rightSum[i] = r_sum - nums[i];
                r_sum-=nums[i];
                leftSum[i] = l_sum + nums[i-1]; 
                l_sum=leftSum[i];
            }
        }
        for(int i = 0 ;i< n;++i){
            answer[i]= abs(rightSum[i]-leftSum[i]);
        }
        return answer;
    }
};


// Optimal approach
// t.c - > O(3n) 
// s.c - > O(3n)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            right -= nums[i];
            ans[i] = abs(left - right);
            left += nums[i];
        }

        return ans;
    }
};
