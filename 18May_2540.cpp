// 2540. Minimum Common Value
//t.c-> O(m+n)
//s.c-> O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){         //both should exist 
            if (nums1[i] == nums2[j]) return nums1[i];
            else if (nums1[i]<nums2[j]) i++;             //increasing that index whose value is lesser in search for equal 
            else j++;                                    //otherwise increase this 
        }
        return -1;                                       //no minimum found
    }
};


int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n);
    vector<int>arr2(m);
    for(int i=0;i<n;++i) cin>>arr1[i];
    for(int i=0;i<m;++i) cin>>arr2[i];

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    Solution obj;
    cout <<obj.getCommon(arr1,arr2);
    return 0;
}
