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
        if(head==NULL)
            return NULL;
        Node* curr=head;

        while(curr){
            Node* currNxt=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=currNxt;
            curr=currNxt;
        }

        curr=head;

        while(curr && curr->next){
            if(curr->random==NULL)
                curr->next->random=NULL;
            else
                curr->next->random=curr->random->next;

            curr=curr->next->next;
            
        }

        Node* newHead=head->next;
        Node* newCurr=newHead;
        curr=head;

        while(curr && newCurr){
            curr->next=curr->next ? curr->next->next : NULL;
            newCurr->next=newCurr->next ? newCurr->next->next : NULL;

            curr=curr->next;
            newCurr=newCurr->next;
        }
        return newHead;

    }
};