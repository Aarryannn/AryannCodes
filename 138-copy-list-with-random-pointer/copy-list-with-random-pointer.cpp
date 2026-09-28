/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        unordered_map <Node* , Node*> mpp;
        mpp[NULL] = NULL;

        Node* newNode = new Node(head -> val);
        
        
        Node* h1 = head;
        Node* d1 = newNode;
        mpp[h1] = d1;

        h1 = h1->next;
// create a deep copy;
        while(h1){
            Node* temp = new Node(h1->val);
            d1-> next = temp;
            mpp[h1] = temp;
            h1 = h1 -> next;
            d1 = d1-> next;
        }

        Node* h2 = head;
        Node* d2 = newNode;

        while(h2){
            Node* temp = h2-> random;
            temp = mpp[temp];
            d2-> random = temp;
            h2 = h2-> next;
            d2 = d2-> next;
        }

        return newNode;





    }
};