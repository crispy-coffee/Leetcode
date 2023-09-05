class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        unordered_map<Node*,Node*> address;
        Node* new_head = new Node(head->val);
        Node* new_tail = new_head;
        Node* tail = head;

        address[head] = new_tail;

        while(tail->next!= nullptr){
            new_tail->next = new Node(tail->next->val);
            tail = tail->next;
            new_tail = new_tail->next;
            address[tail] = new_tail;
        }

        tail = head;
        new_tail = new_head;

        while(tail != nullptr){
            new_tail->random = address[tail->random];
            tail = tail->next;
            new_tail = new_tail->next;
        }

        return new_head;
    }
};