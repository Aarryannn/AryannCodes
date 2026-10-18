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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode();
        ListNode* even = new ListNode();
        
        ListNode* oddtail = odd;
        ListNode* eventail = even;
        int i = 0;
        while(head){
            if(i % 2 == 0){
                oddtail->next = head;
                oddtail= oddtail->next;
            }else{
                eventail->next = head;
                eventail = eventail-> next;
            } 
            i++;
            head = head->next;
        }


        oddtail->next = even -> next;
        eventail->next = NULL;


        return odd->next;

    }
    
};