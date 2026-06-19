#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Treenode{
// public : 
//     int val ; 
//     Treenode *left;
//     Treenode *right;

//     Treenode(int val1){
//         val =val1;
//         left = nullptr;
//         right = nullptr;
//     }

//     Treenode(int val1 , Treenode *left1 , Treenode *right1){
//         val = val1;
//         left = left1;
//         right = right1;
//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;     //2d vector to store result
        if (root == NULL ) return ans;        //root is null 
        queue<TreeNode*>q;           //queue to track progress sequentially left to right
        q.push(root);                //pushing first element to queue
        while(!q.empty()){           //run until queue becomes empty
            int size=q.size();
            vector<int>level;        //storing nodes at same level 
            for(int i = 0 ;i<size;++i){
                TreeNode* node =q.front();    //taking front element as node variable
                q.pop();                      //poping it from queue
                if (node -> left) q.push(node->left);   //if node's left exist then push it in queue
                if (node -> right) q.push(node->right);   //if node's left exist then push it in queue
                level.push_back(node->val);   //push that node in level
            }
            ans.push_back(level);  //push all nodes's at same level in ans vector
        }
        return ans;
    }
};

// Example usage
int main() {
    // Create a sample binary tree:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the level order traversal
    for (auto level : result) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}

