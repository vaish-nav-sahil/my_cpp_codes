// 3499. Maximize Active Section with Trade I
// https://leetcode.com/problems/maximize-active-section-with-trade-i/description/?envType=daily-question&envId=2026-07-21

#include<bits/stdc++.h>
using namespace std;

// i will use 0 and 1 named blocks instead of active and inactive blocks respectively 

//Approach (target 1s and find max pair sum of zero blocks)
// Here we should be only concerned with number of zero in neighbours of 1 or contiguous block of one 
// 1. find zeroBlocks sizes in a vector
// 2. find max pair sum -> M
// 3. M + count of existing ones 
//T.C : O(n)
//S.C : O(n)

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();

        //existing count of 1s
        int oneCount = count(begin(s), end(s), '1');

        vector<int> zeroBlocks;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {          //as soon as you get zero 
                int start = i;         //just start the count 
                while(i < n && s[i] == '0') i++;        //search until string goes empty and the number is 0

                zeroBlocks.push_back(i-start);          //once you finish push that count(i-start) by zeroBlock vector 
            } else {
                i++;
            }
        }

        int maxPairSum = 0;           
        //max(inactiveBlocks[i] + inactiveBlocks[i-1])
        for(int i = 1; i < zeroBlocks.size(); i++) {                    
            maxPairSum = max(maxPairSum, zeroBlocks[i] + zeroBlocks[i-1]);   //maintain max pair sum   
        }

        return maxPairSum + oneCount;                  //return max pair sum found + no of 1's
    }
};

int main(){
    string s;
    cin>>s;
    Solution obj;
    cout<<obj.maxActiveSectionsAfterTrade(s);
    return 0;
}
