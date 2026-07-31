// 3014. Minimum Number of Pushes to Type Word I
// link -> https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/?envType=daily-question&envId=2026-07-30

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int count =0;
        
        int q  = n/8;
        int rem = n%8;
        int i=1;
        while(i<=q){
            count = count+8*i;
            i++;
        }
        return count+rem*i ;
    }
};

int main(){

    return 0;
}
