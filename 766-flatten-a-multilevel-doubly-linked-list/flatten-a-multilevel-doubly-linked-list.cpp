/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr){
            if(curr->child){
                Node* newNode = flatten(curr->child);
                curr->child = NULL;
                Node* next = curr-> next;

                curr->next = newNode;
                newNode->prev = curr;
                while(curr->next){
                    curr = curr->next;
                }
                if(next){
                    curr->next = next;
                    curr->next->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};