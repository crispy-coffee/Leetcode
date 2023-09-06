class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        
        vector<ListNode*> answer;
        temp = head;

        for(int i=0; i<k; i++){
            ListNode* tail = temp;
            answer.push_back(temp);

            int chotasize = size/k;
            int extra = size%k;

            for(int count=0; count<chotasize-1 and tail; count++){
                tail = tail->next;
            }

            if(chotasize and extra and tail){
                tail = tail->next;
                size--;
            }

            if(tail){
                temp = tail->next;
                tail->next = NULL;
            }

        }

        return answer;
    }   
};