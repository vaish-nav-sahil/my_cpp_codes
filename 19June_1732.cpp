// 1732. Find the Highest Altitude
// https://leetcode.com/problems/find-the-highest-altitude/description/?envType=daily-question&envId=2026-06-19

// t.c -> O(n)
// s.c -> O(1)

// Approach -> 
// 1.Initialize max to 0 not INT_MIN this time.
// 2.Do addition of gain elements in a new start variable.
// 3.update max in each step.
// 4.Return max .


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0 ;
        int start =0;       
        for(int i=0;i<gain.size();++i){
            start +=gain[i];
            maxi = max(maxi,start);
        }
        return maxi;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0 ; i< n ;++i) cin>>arr[i];

    Solution obj;
    cout<<obj.largestAltitude(arr);
    return 0;
}
