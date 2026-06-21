//Going absolutely greedy nothing else 

// 1833. Maximum Ice Cream Bars
// link -> https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21

// t.c -> O(nlog(n)+n)
// s.c -> O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count =0;
        sort(costs.begin(),costs.end());
        for(auto it : costs){
            if (coins >= it ){
                count++;
                coins -= it ;
            }
            else return count;
        }
        return count;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;++i) cin>>arr[i];

    int coins ; 
    cin>>coins;

    Solution obj;
    cout<<obj.maxIceCream(arr,coins);
    return 0;
}
