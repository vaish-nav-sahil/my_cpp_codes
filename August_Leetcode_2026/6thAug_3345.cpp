// 3345. Smallest Divisible Digit Product I
// link -> https://leetcode.com/problems/smallest-divisible-digit-product-i/description/?envType=daily-question&envId=2026-08-06

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(n<101){
            int p = n;

            int pro =1;
            while(p>0){
                int rem = p % 10;
                pro=pro*rem;
                p=p/10;
            }     
            if (pro % t == 0 ) return n;
            n++;
        }
        return -1;
    }
};

int main(){

    return 0;
}