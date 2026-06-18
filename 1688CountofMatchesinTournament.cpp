// //INTUTION -> (see below for t.c -> O(1)
// Simply do whatever is saying 

// T.c-> O(log n to the base 2)
//S.c -> O(1)


// class Solution {
// public:
//     int numberOfMatches(int n) {
//         int match=0;        
//         while(n>1){       
//             if (n%2 == 0) {
//                 n=n/2;
//                 match += n;
//             }
//             else{
//                 n=(n-1)/2;
//                 match+=n;
//                 n=n+1;
//             }
//         }
//         return match;

//     }
// };


//Approach -> Simple observation

// t.c -> O(1)
// s.c -> O(1)

class Solution{
public : 
    int numberOfMatches(int n){
        return n-1;
    }

};
