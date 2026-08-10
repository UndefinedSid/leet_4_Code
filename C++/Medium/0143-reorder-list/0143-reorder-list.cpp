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
    /*
    // stack method

    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr=head;
        while(curr != nullptr){
            st.push(curr);
            curr=curr->next;
        }

        int k=st.size() / 2;
        curr=head;

        while(k--){
            ListNode* topNode=st.top();
            st.pop();
            ListNode* temp=curr->next;
            curr->next=topNode;
            topNode->next=temp;
            curr=temp;
        }
        curr->next=NULL;

    }

    */
    // Recursion Method

    ListNode* curr;
    void finder(ListNode* head){
        if(head==NULL)
            return;

        finder(head->next);
        ListNode* temp=curr->next;
        if(curr==head){
            curr->next=NULL;
            return;
        }else if(curr->next==NULL)
            return;

        curr->next=head;
        head->next=(temp==head) ? NULL : temp;
        curr=temp;

    }

    void reorderList(ListNode* head){
        if(head==NULL)
            return;

        curr=head;

        return finder(head);
    }
};