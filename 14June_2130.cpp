// 2130. Maximum Twin Sum of a Linked List
// link -> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//Approach -> 
// 1.copy all the value in a vector or array 
// 2.then simply use shrinking two pinter towards mid and get max out of all combinations

// T.c -> O(N+N/2)
// s.c-> O(N)

// class Solution {
// public : 
//     vector<int>result;                     // result vector 
//     int pairSum(ListNode* head){
//         ListNode* temp = head ;
//         while(temp){
//             result.push_back(temp->val);           //copying linked data to result vector 
//             temp=temp->next;                
//         }
//         int maxi=INT_MIN;
//         int n = result.size();
//         int i =0, j=n-1;                        //low and high pointers 
//         while(i<j){
//             maxi = max(maxi,result[i]+result[j]);
//             i++,j--;
//         }
//         return maxi;
//     }
// };


// Optimised Approach -> 
// 1.find mid of the linked list and then break it and remember to store its next for further traversal
// 2.now reverse the first part of the linked list .
// 3.you got two linked list of exact two half now , traverse and get max from all possible combinations

// T.c ->O(n/2+n/2+n/2)
// s.c -> O(1)

class Solution {
public:
    ListNode* midOfLl(ListNode* head){
        ListNode* slow = head ; 
        ListNode* fast = head ; 
        
        while(fast->next && fast ->next -> next){
            slow = slow -> next ; 
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){      
        ListNode* prev = nullptr;
        ListNode* curr = head ; 
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev= curr;
            curr = temp;
        }
        return prev;                    //return previous as current would be nullptr becasue of while condition
    }

    int pairSum(ListNode* head) {

        ListNode* middle = midOfLl(head);                
        ListNode* second = middle -> next ;        //store it for travsering in second part 
        middle->next = NULL;                       //set middle->next to null 

        ListNode* reversed_ll = reverse(head);     //reverse the first part
        int maxi = INT_MIN;
        while(reversed_ll){
            maxi = max(maxi,reversed_ll->val + second -> val);
            reversed_ll = reversed_ll->next;
            second = second -> next;
        }
        return maxi;

    }
};

int main() {
    
    int n;
    cout << "Enter number of nodes (given even as per question): ";
    cin >> n;

    if (n == 0) return 0;

    int x;
    cin >> x;

    ListNode* head = new ListNode(x);
    ListNode* tail = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    Solution obj;
    cout << "Maximum Twin Sum = " << obj.pairSum(head) << endl;

    return 0;
}
