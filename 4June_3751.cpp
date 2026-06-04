class Solution {
public:
    int waviness(int num){
        if (num<=100 ) return 0;
        string s = to_string(num);
        int i=1,count=0;
        while(i<s.size()-1){
            if ((s[i-1]< s[i] && s[i]>s[i+1]) || (s[i-1]> s[i] && s[i]<s[i+1])) count++;
            i++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {

        if (num1>=1 and num2<=100) return 0;
        int result=0;
        for(int i=num1;i<=num2;++i){
            result = result + waviness(i);
        }
        return result; 
    

    }
    
    
};
