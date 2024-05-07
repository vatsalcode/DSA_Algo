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
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);   
    ListNode* node = head;
    int carry = 0;
    while (node) {
        int sum = node->val * 2 + carry;   
        node->val = sum % 10;   
        carry = sum / 10;   
        if (!node->next && carry) {   
            node->next = new ListNode(carry);   
            break;
        }
        node = node->next;   
    }
    return reverseList(head);
    }
};