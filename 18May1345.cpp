//1345. Jump Game IV

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n= arr.size();

        if (n==1) return 0;

        unordered_map<int,vector<int>>mp; //map to store indices 
        for(int i=0;i<n;++i){
            mp[arr[i]].push_back(i);
        }

        vector<bool>visited(n,false);  //visited array to avoid revisit 

        queue<int>que;    //track bfs
        que.push(0);
        visited[0]=true;

        int steps = 0 ; 

        while(!que.empty()){
            int size = que.size();//level
            while(size--){
                int curr=que.front();
                que.pop();

                int left = curr - 1 ; 
                int right = curr + 1 ;

                if (curr == n-1 ) return steps; //reached last index

                if (left >=0 && !visited[left]){ //not out of bound   and  not visited
                    que.push(left);
                    visited[left] = true;
                }

                if (right >=0 && !visited[right]){ //not out of bound   and  not visited
                    que.push(right);
                    visited[right] = true;
                }

                for(int idx : mp[arr[curr]]){ // adding same value jumps 
                    if (!visited[idx]){
                        que.push(idx);
                        visited[idx]=true;
                    }
                }
                mp.erase(arr[curr]); //erased the 
            }
            steps++; 
        }
        return -1;
    }
};  


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        arr.push_back(x);
    }

    Solution obj;
    cout<<obj.minJumps(arr);

    return 0;
}
