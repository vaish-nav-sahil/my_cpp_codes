#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force Approach -> 
    // t.c -> O(n+n/2)
    // s.c -> O(1)

    int gcdOfOddEvenSums(int n) {
        int oddSum = 0 , evenSum = 0;
        int i = 1 , j = 2 ;
        while(n--){
            oddSum +=2;
            evenSum +=2;
        }

        int gcd = 1 ;
        for(int i=2 ; i<=oddSum/2;++i){
            if ((oddSum % i == 0 ) && (evenSum % i == 0)){
                gcd = i ; 
                continue;
            } 
            
        }

        return gcd;
    }


// Approach 2-> 
// t.c -> O(1)
// s.c -> O(1)
// This also works can you guess why ?
// Sum of first n odd natural numbers -> n^2
// Sum of first n even natural numbers -> n(n+1)

// now we have to find gcd of (n^2 , n(n+1))
//                    gcd of n(n , n+1)
//                    gcd of n(gcd of n & n+1)
//                    gcd of n(1)
//                    gcd is n

    int gcdOfOddEvenSums(int n) {
        return n ;
    }
};



int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.gcdOfOddEvenSums(n);
}
