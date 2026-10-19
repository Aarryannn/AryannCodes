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
    ListNode* mergeLists(ListNode* h1, ListNode* h2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(h1 != NULL && h2 != NULL){
            if(h1->val <= h2->val){
                tail->next = h1;
                h1= h1->next;
            }else{
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        if(h1 != NULL)  tail->next = h1;
        else tail->next = h2;

        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* middle = slow->next;
        slow->next = NULL;

        ListNode* left = sortList(head);
        ListNode* right = sortList(middle);

        ListNode* ans = mergeLists(left,right);
        return ans;

    }
};