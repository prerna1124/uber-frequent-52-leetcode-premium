package Java;

class MergekLL {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((node1, node2) -> (node1.val - node2.val));
        
        for(int i = 0; i < lists.length; i++) {
            if(lists[i] != null)
                minHeap.add(lists[i]);
        }
        
        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;
        
        while(minHeap.size() != 0) {
            ListNode minNode = minHeap.poll();
            
            temp.next = minNode;
            temp = temp.next;
            
            minNode = minNode.next;
            if(minNode != null) {
                minHeap.add(minNode);
            }
            
        }
        
        return dummy.next;
    }
}
