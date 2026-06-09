// t.c -> O(n);
// s.c -> O(1);


#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    ll maxTotalValue(vector<int>& nums, int k) {
        ll mini=LONG_MAX,maxi=LONG_MIN;
        for (int i = 0;i<nums.size();++i){
            mini=min(mini,(ll)nums[i]);
            maxi=max(maxi,(ll)nums[i]);
        }
        
        return k*(maxi-mini);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0 ;i < n ;++i) cin>>arr[i];
    int k;
    cin>>k;
    Solution obj;

    cout<<obj.maxTotalValue(arr,k);
    return 0;
}

