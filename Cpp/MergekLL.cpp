class MergekLL {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* node1, const ListNode* node2) {
            return node1->val > node2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr)
                minHeap.push(lists[i]);
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            
            temp->next = minNode;
            temp = temp->next;
            
            minNode = minNode->next;
            if(minNode != nullptr) {
                minHeap.push(minNode);
            }
            
        }
        
        return dummy->next;
    }
};
