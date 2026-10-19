/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        // find middle;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = NULL;

// revrse
        ListNode* prev = NULL; 
        ListNode* next = NULL; 
        

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 

// arrange alternatively:
    ListNode* h1 = head;
    ListNode* h2 = prev;

    while(h2){
        ListNode* h1n = h1->next;
        ListNode* h2n = h2->next;

        h1->next = h2;
        h2->next = h1n;

        h1 = h1n;
        h2 = h2n;
    }


    }
};