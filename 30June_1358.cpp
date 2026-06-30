class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3]={-1,-1,-1},cnt=0,n=s.size();
        for(int i=0;i<n;i++){
            hash[s[i]-'a'] = i;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
                cnt+=1+min({hash[0],hash[1],hash[2]});
            }
        }
        return cnt;
    }
};
