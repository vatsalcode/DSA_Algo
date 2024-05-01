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
    ListNode* reverseList(ListNode* head) {
        // if(!head || !head->next)return head;
        // ListNode* ans= reverseList(head->next);
        // head->next->next=head;
        // head->next=NULL;
        // return ans;

        ListNode* prv=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prv;
            prv=curr;
            curr=next;
        }
        return prv;

    }
};