#Definition for singly-linked list.
"""
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sobra=0
        res=ListNode(0)
        b=res
        while((l1 is not None) or (l2 is not None)):
            now=sobra
            if(l1 is not None):
                now+=l1.val
                l1=l1.next
            if(l2 is not None):
                now+=l2.val
                l2=l2.next
            sobra=now//10
            b.next=ListNode(now%10)
            b=b.next
        if(sobra>0):
            b.next=ListNode(1)
        return res.next