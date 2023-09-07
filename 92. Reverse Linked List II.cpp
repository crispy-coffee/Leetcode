class Solution {
public:
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head;

        while(k--){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = next;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        int count = 1;
        while(count < left){
            prev = curr;
            curr = curr->next;
            count++;
        }

        ListNode* temp = reverse(curr, right-left+1);
        if(prev)
            prev->next = temp;
        else
            return temp;

        return head;
    }
};