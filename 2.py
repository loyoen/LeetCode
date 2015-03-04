#Add Two Numbers 
'''
    just add
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        tmpl1 = l1
        tmpl2 = l2
        AnsNode = None
        tmpNode = None
        Carry = 0
        while (tmpl1!=None or tmpl2!=None):
            ans1 = 0
            ans2 = 0
            if tmpl1 == None:   ans1 = 0
            else:   
                ans1 = tmpl1.val
                tmpl1 = tmpl1.next
            if tmpl2 == None:   ans2 = 0
            else:   
                ans2 = tmpl2.val
                tmpl2 = tmpl2.next
            thisNode = ListNode((ans1+ans2+Carry)%10)
            Carry = (ans1+ans2+Carry)/10
            if AnsNode == None:
                AnsNode = thisNode
                tmpNode = AnsNode
            else:
                tmpNode.next = thisNode
                tmpNode = thisNode
        
        if Carry>0:
            thisNode = ListNode(Carry)
            tmpNode.next = thisNode
        return AnsNode
l1 = ListNode(2)
l12 = ListNode(4)
l13 = ListNode(3)
l2 = ListNode(5)
l22 = ListNode(6)
l23 = ListNode(4)
l1.next = l12
l12.next = l13
l2.next = l22
l22.next = l23
Test = Solution()
l = Test.addTwoNumbers(l1,l2)
while l!=None:
    print l.val
    l = l.next
