class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Approach 1 Using space
        /*
        map<int,int> store;

        while(head){
            store[head->val]++;
            head = head->next;
        }

        ListNode* root = new ListNode(-1);
        ListNode* tail = root;

        for(auto child: store){
            if(child.second == 1){
                tail->next = new ListNode(child.first);
                tail = tail->next;
            }
        }
        return root->next;
        */

        ListNode* root = new ListNode(-1, head);
        ListNode* tail = root;

        while(head){
            if(head->next and head->val == head->next->val){
                
                while(head->next and head->val == head->next->val)
                    head = head->next;

                tail->next = head->next;
            }else{
                tail = tail->next;
            }
            head = head->next;
        }
        return root->next;
    }
};