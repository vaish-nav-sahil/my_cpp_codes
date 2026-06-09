// 506. Relative Ranks 
// link -> https://leetcode.com/problems/relative-ranks/description/
//basic approach
// t.c -> O(n^2)
// s.c -> O(n)


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int>sorted = score;        
        vector<string>ans;
        sort(sorted.begin(),sorted.end(),greater<int>());   //sorted in desc order

        for(int i = 0 ;i < n ; ++i){                 //O(n^2)
            if (score[i] == sorted[0] ) {            //map with first index of sorted for gold
                ans.push_back("Gold Medal"); 
            }
            else if (score[i] == sorted[1]){         //map with first index of sorted for silver
                ans.push_back("Silver Medal");
            }
            else if (score[i] == sorted[2]){         //map with first index of sorted for Bronze
                ans.push_back("Bronze Medal");
            }
            else{
                int num = i ;  
                for (int i = 3 ; i < n ; ++i){       //check with index 2 from sorted array as g,s,b are done
                    if (score[num] == sorted[i]){
                        string s = to_string((i+1)); 
                        ans.push_back(s);            //push back (i+1)th position form sorted array
                    }
                }
            }
        }
        return ans;
    }

    
};


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i) cin>>arr[i];

    Solution obj;
    
    vector<string>grr=obj.findRelativeRanks(arr);

    for(auto it : grr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

//second approach using unordered map or hash map

//t.c -> O(n)
//s.c -> O(n)
// class Solution {
// public:
//     vector<string> findRelativeRanks(vector<int>& score) {
//         int n = score.size();

//         vector<int>sorted=score;
//         sort(sorted.begin(),sorted.end(),greater<int>());

//         vector<string>ans;
//         unordered_map<int,int>mpp;

//         for(int i= 0 ;i<n;i++){
//             mpp[sorted[i]]=i+1;
//         }

//         for(int i=0;i<n;++i){
//             int current_rank = mpp[score[i]];
//             if (current_rank == 1) ans.push_back("Gold Medal");
//             else if (current_rank == 2) ans.push_back("Silver Medal");
//             else if (current_rank == 3) ans.push_back("Bronze Medal");
//             else{
//                 string s = to_string(current_rank);
//                 ans.push_back(s);
//             }

//         }
//         return ans;
//     }
// };
