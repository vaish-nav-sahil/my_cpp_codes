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
};
