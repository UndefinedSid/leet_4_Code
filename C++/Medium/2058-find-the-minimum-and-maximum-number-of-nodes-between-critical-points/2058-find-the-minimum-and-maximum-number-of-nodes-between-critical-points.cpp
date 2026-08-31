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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> temp;

        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nxt=curr->next;
        int idx=1;

        while(curr->next){
            if(curr->val > prev->val && curr->val > nxt->val){
                temp.push_back(idx);
            }else if(curr->val < prev->val && curr->val < nxt->val){
                temp.push_back(idx);
            }
            idx++;
            prev=curr;
            curr=nxt;
            nxt=nxt->next;

        }
        sort(temp.begin(),temp.end());
        int n=temp.size();
        int maxi=-1;
        int mini=INT_MAX;

        for(int i=0;i<n-1;i++){
            mini=min(mini,temp[i+1]-temp[i]);
        }
        if(temp.size() >= 2){
            maxi=temp[n-1] - temp[0];
        }

        if(mini==INT_MAX)
            mini=-1;

        return {mini,maxi};
    }
};