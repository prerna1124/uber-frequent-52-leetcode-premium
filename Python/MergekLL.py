class MergekLL:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        minHeap = []
        for lst in lists:
            if lst:
                heapq.heappush(minHeap, (lst.val, lst))
                
        dummy = ListNode(-1)
        temp = dummy
        
        while minHeap:
            _, minNode = heapq.heappop(minHeap)
            
            temp.next = minNode
            temp = temp.next
            
            minNode = minNode.next
            if minNode:
                heapq.heappush(minHeap, (minNode.val, minNode))
        
        return dummy.next
