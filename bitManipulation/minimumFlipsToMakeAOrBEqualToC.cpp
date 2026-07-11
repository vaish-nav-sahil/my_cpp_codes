#include<bits/stdc++.h>
using namespace std ;

// 1318. Minimum Flips to Make a OR b Equal to c
// link -> https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

// basic approach -> see every bit by bit of c from right and do min necessary changes in a and b 

// 1. a&1 -> gives rightmost bit
// 2. a >>= 1 OR a = a >> 1 deletes right most bit i.e right shift operation 

// CASES ->            or operator ->   (if any of both is 1 in or operrator then answer is 1 )
// 1) if c has right most bit as 1 then only time when we need a flip is when both a and b are 0 so we will flip any of these and increase flips by 1 

// 2) if c has right most bit as 0 then only possible case is both should necessarily be 0 otherwise it may result as 1 so we will increase flips by 1 or 2 depending on rightmost bit of a and b 

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips=0;
        while(a || b || c ){
            int right_most_bit_c = c&1;
            int right_most_bit_b = b&1;
            int right_most_bit_a = a&1;

            if (right_most_bit_c && (right_most_bit_b==0 && right_most_bit_a ==0 )) {
                flips++;
            }
            else if (!right_most_bit_c ){
                if (right_most_bit_a){
                    flips++;
                    
                }
                if (right_most_bit_b){
                    flips++;
                } 
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flips;
    }
};

//Approach-2 (Using inbuild function)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = (a | b) ^ c;
        return __builtin_popcount(result) + __builtin_popcount((a & b) & (result));
    }
};

int main(){
    int a , b,c;
    cin>>a>>b>>c;
    Solution obj;
    cout<<obj.minFlips(a,b,c);
    return 0;
}