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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode*p=new ListNode(0,head);
        ListNode*q=p;
        while(q!=NULL)
        {
            int ans=0;
            ListNode*r=q->next;
            while(r!=NULL)
            {
                ans+=r->val;
                if(ans==0){
                    q->next=r->next;
                }
                r=r->next;
            }
            q=q->next;
        }
        return p->next;
    }
};