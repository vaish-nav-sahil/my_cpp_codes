// 3838. Weighted Word Mapping
// link -> https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-13
// t.c -> O(n*each_word_length)
// s.c -> O(1)

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";                //empty string for storing ans
        for(string s : words){              
            int wt_value=0;
            for(char ch : s){
                int index = ch - 'a';          //explicit type conversion into integer 
                wt_value+=weights[index];       //calculating wt of each string 
            }

            int after_mod = wt_value%26;        
 
            int rev_map_index = 122-after_mod;     //reverse mapping
            
            ans= ans + (char)rev_map_index;        //explicit type conversion into char 
        return ans;
    }
};
