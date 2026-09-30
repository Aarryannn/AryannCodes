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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        // check for k nodes available
        ListNode* temp = head;
        while(count < k){
            if(!temp) return head;
            temp = temp->next;
            count++;
        }

        // recursive call for left all nodes
        ListNode* prevNode = reverseKGroup(temp, k);


        // revrsing current grp;
       count = 0;
       ListNode* curr = head;
       ListNode* next;
       while(count < k){
        next = curr -> next;
       curr -> next = prevNode;
       prevNode = curr;
       curr = next;
       count++;
       }
     return prevNode;

    }
};