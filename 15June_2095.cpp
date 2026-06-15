// t.c -> O(n/2)
// s.c -> O(1)

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return nullptr;       //early out condition if head has one or none nodes

        ListNode* slow = head;
        ListNode* prev = nullptr;          
        ListNode* fast = head;

        while(fast && fast->next){
            prev = slow;                   //one less than mid 
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;          //link changes mid -1 should point to mid +1  
        delete slow;                      //freing the mid node

        return head;
    }
};
