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

    ListNode* reverseN(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr){
            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast-> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* mid = slow;
        mid = reverseN(mid);

        while(mid){
            if(mid-> val != head->val) return false;

            mid = mid->next;
            head = head-> next;
        }

        return true;

    }
};