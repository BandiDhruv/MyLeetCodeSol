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
    ListNode*rev(ListNode*head)
    {
        ListNode*curr=head,*prev=NULL,*ahead=NULL;
        while(curr){
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode*fast=head,*slow=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*second=rev(slow->next);
        slow->next=NULL;
        ListNode*first=head;
        while(second)
        {
            ListNode*temp1=first->next;
            ListNode*temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
            
    }
};