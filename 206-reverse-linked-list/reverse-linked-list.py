# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prv=None
        curr=head
        next=None

        while curr!= None:
            next=curr.next
            curr.next=prv
            prv=curr
            curr=next
        return prv
        