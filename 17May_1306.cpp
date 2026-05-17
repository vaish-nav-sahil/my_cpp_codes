// 1306. Jump Game III

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool solve(vector<int>& arr,int n, int start){

        if (start>=n || start <0 || arr[start] <0) return false;  // base case -> out of bounds and if visiting again the marked visited index 

        if (arr[start]==0) return true; //reached the location
        
        arr[start]*=-1; //marking as visited to avoid loop (magnitude of arrays value is preserved only direction is changed )

        bool left = solve(arr,n,start-arr[start]);
        bool right = solve(arr,n,start+arr[start]);
        
        return left || right;   // returns true if any true else false
    }

    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        return solve (arr,n,start);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;++i) {
        int x;
        cin>>x;
        arr.push_back(x);
    }

    int start ;
    cin>>start;

    Solution obj;
    bool result = obj.canReach(arr,start);
    cout<<(result ? "true" : "false");
}
