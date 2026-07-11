// 2685. Count the Number of Complete Components
// link -> https://leetcode.com/problems/count-the-number-of-complete-components/description/?envType=daily-question&envId=2026-07-11

// Complexity-> 

// Time: O(V+E)
// DFS visits every node and edge once.
// Each node is checked once after its component is collected.

// Space: O(V+E)
// Adjacency list: O(V+E)
// Visited array: O(V)
// Component vector: up to O(V)
// DFS recursion stack: up to O(V)
 

//Approach -> simple approach
// 1.do dfs traversal and store elements of connected component inside a component vector 
// 2.see every time you visit every node inside a connected component it must have all edges with other nodes inside same connected component so put a condition adj[node].size() == n-1 (here n is size of component vector)

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u,vector<bool>& visited, vector<int>& component) {
        visited[u] = true;
        component.push_back(u); //push_back in component vector 

        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        //unordered map for my understaning you can do directly through 2d vector
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;   //will store all connected components
                dfs(adj, i, visited, component);
                int size = component.size();
                bool complete = true;    //assuming everything is ok 
                for (int node : component) {
                    if (adj[node].size() != size - 1) {       //here comes the condition
                        complete = false;            //not equals then break
                        break;
                    }
                }
                if (complete)
                    count++;       //increase the count 
            }
        }
        return count;
    }
};

int main(){
    
    return 0;
}
