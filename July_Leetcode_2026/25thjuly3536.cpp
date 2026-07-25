#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0,sec_maxi=0;
        
        while(n>0){
            int rem = n%10;
            bool changed=false;
            if (rem>maxi) {
                sec_maxi = maxi;
                maxi=rem;
                changed =true;
            }
            if (!changed && rem>sec_maxi) {
                sec_maxi=rem;
            }
            n=n/10;
            changed=false;
        }
        return maxi*sec_maxi;
    }
};

int main(){
    int n;
    cin>>n;
    Solution obj;
    cout<<obj.maxProduct(n);
    return 0;
}
