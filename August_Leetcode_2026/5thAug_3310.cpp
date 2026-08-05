// 3310. Remove Methods From Project
// link -> https://leetcode.com/problems/remove-methods-from-project/description/?envType=daily-question&envId=2026-08-05

// Question hints to be a graph question

// Suspicious nodes -> suspicious node k if hits any other node either directly or indirectly then that node too is considered "Suspicious" 

// Unsuspicious nodes -> which aren't hit by any direct or indirect suspicious nodes 

// Removable nodes -> those suspicious nodes which aren't hit by any other unsuspicous node . Basically suspicious nodes form a group and we can't remove them until and unless any of the unsuspicious nodes hits any other member of suspicious group .

//Approach-1 - Using BFS

// 1. Indegree array
// 2. Traversal from Kth node will tell which group is suspicious and mark those nodes in an boolean array.
// 3. Meanwhile update indegree of nodes too.
// 4. if (suspicious and indegree != 0)  then print all nodes as you can't remove any suspicious group as they        are hit by unsuspciious nodes too otherwise ingdegree would have been 0 
//    else (remove that node)

#include<bits/stdc++.h>
using namespace std;

//T.C : O(V+E) , V = number of nodes(methods), E = number of edges
//S.C : O(V+E), V = number of nodes(methods), E = number of edges

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        //O(V+E), V = nodes , E = edges
        //graph - adjacency list
        vector<vector<int>> adj(n); //u -> {ngbr1, ngbr2} //O(V+E)
        vector<int> inDegree(n, 0); //O(V)
        vector<bool> suspicious(n, false);//O(V)

        for(auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        //BFS
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();

            for(int &ngbr : adj[curr]) {
                inDegree[ngbr]--;
                if(!suspicious[ngbr]) {
                    que.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> result;
        bool cannotRemove = false;
        
        for(int i = 0; i < n; i++) {
            if(suspicious[i] && inDegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) {
                result.push_back(i);
            }

        }

        if(cannotRemove) {
            vector<int> vec(n); //0, 1, 2,... n-1
            for(int i = 0; i < n; i++) {
                vec[i] = i;
            }
            return vec;
        }
        
        return result;


    }
};

int main(){

    return 0;
}