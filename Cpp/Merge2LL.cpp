class Merge2LL {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(list1 != nullptr || list2 != nullptr) {
            
            if(list1 == nullptr) {
                temp->next = list2;
                list2 = list2->next;
            } else if(list2 == nullptr) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                if(list1->val < list2->val) {
                    temp->next = list1;
                    list1 = list1->next;
                } else {
                    temp->next = list2;
                    list2 = list2->next;
                }
            }
            
            temp = temp->next;
        }
        
        return dummy->next;
    }
};
