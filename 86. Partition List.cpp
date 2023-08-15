class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        if(!head or !head->next)
            return head;

        ListNode* smallhead = new ListNode(-1);
        ListNode* small = smallhead;
        ListNode* largehead = new ListNode(-1);
        ListNode* large = largehead;

        ListNode* tail = head;

        while(tail){
            if(tail->val < x){
                small->next = tail;
                small = small->next;
            }else{
                large->next = tail;
                large = large->next;
            }
            tail = tail->next;
        }
        
       small->next = largehead->next;
       large->next = NULL;
       return smallhead->next;

    }
};