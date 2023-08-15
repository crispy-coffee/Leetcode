class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next)
            return head;

        ListNode* oddhead = head;
        ListNode* oddtail = oddhead;

        ListNode* evenhead = head->next;
        ListNode* eventail = evenhead;

        while(oddtail and oddtail->next and oddtail->next->next){

            oddtail->next = oddtail->next->next;
            if(eventail->next)
                eventail->next = eventail->next->next;

            oddtail = oddtail->next;
            eventail = eventail->next;

        }

        oddtail->next = evenhead;

        return oddhead;
    }
};