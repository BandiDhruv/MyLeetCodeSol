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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p=head,*q=head;
        int count=0;
        while(p!=NULL){
            p=p->next;
            count++;
        }
        // cout<<count;
        int end=count-n,e=count-n;
        if(count==1 && n==0)return head;
        if(count==1 && n==1)return nullptr;
        if(end==0)return head->next;
        while(end>1)
        {
            q=q->next;
            end--;
        }
        if(q && q->next && q->next->next)
            q->next=q->next->next;
        else q->next=nullptr;
        return head;

    }   
};