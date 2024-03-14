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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return {};
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &it:lists)
        {
            if(it==nullptr)continue;
            while(it!=nullptr)
            {
                pq.push(it->val);
                it=it->next;

            }
        }
        // while(!pq.empty()){cout<<pq.top()<<"  ";pq.pop();}
        ListNode* p=new ListNode();
        ListNode*q=p;
        while(!pq.empty())
        {
            ListNode*t=new ListNode(pq.top());
            p->next=t;
            p=p->next;
            pq.pop();
        }
        return q->next;
    }
};