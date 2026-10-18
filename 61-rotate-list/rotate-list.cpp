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
    ListNode* rotateRight(ListNode* head, int k) {
        // find size of list;
        int size = 0;
        ListNode* temp = head;
        ListNode* tail;
        while(temp){
            size++;
            tail = temp;
            temp = temp->next;
        }
        if(size == 0) return NULL;
        k = k % size; 
        if (k == 0) return head;

        int runTime = size - k;
        ListNode* newStart;
        temp = head;

        for(int i  = 0 ; i < runTime - 1 ; i++){
            temp = temp->next;
        }
        newStart = temp->next;

        temp->next = NULL;
        tail->next = head;

        head = newStart;

        return head;

    }
};