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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* ans = head->next;
         ListNode* fst = head;
         ListNode* snd = head->next;
         ListNode* prev = NULL;

         while(fst != NULL && snd != NULL){

            ListNode* third = snd -> next;
            snd -> next = fst;
            fst-> next = third;
            if(prev){
                prev -> next = snd;
            }

            if(third){
                prev = fst;
                fst = third;
                snd = fst->next;
            }else{
                return ans;
            }
         }
return ans;


    }
};