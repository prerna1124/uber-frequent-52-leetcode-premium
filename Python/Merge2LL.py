class Merge2LL:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        dummy = ListNode(-1)
        temp = dummy
        
        while list1 or list2:
            
            if not list1:
                temp.next = list2
                list2 = list2.next
            elif not list2:
                temp.next = list1
                list1 = list1.next
            else:
                if list1.val < list2.val:
                    temp.next = list1
                    list1 = list1.next
                else:
                    temp.next = list2
                    list2 = list2.next
            
            temp = temp.next
        
        return dummy.next
