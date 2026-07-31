// 3016. Minimum Number of Pushes to Type Word II
// link -> https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/


#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);

        for(auto ch : word){
            mp[ch-'a']++;
        }

        sort(begin(word),end(word),greater<int>());

        int result =0;

        for(int i=0;i<26;i++){
            int freq = mp[i];

            int press = i/8+1;

            result += press * freq;
        }
        return result;
    }
};

int main(){

    return 0;
}

