class Trie {
public:
    class trie{
        public:
        bool isterminal = false;
        // Using array
        // trie* child[26] = {};

        // Using vector
        vector<trie*> child;
        trie(){
            child.resize(26);
            child = {};
        }
    };

    trie* node;
    Trie() {
        node = new trie();
    }
    
    void insert(string word) {
        
        trie* temp = node;;
        for(char ch:word){
            int index = ch-'a';
            if(temp->child[index] == NULL){
                temp->child[index] = new trie();
            }
            temp = temp->child[index];
        }

        temp->isterminal = true;
    }
    
    bool search(string word) {

        trie* temp = node;;
        for(char ch:word){
            int index = ch-'a';
            if(temp->child[index] == NULL){
                return false;
            }
            temp = temp->child[index];
        }

        return temp->isterminal;
    }
    
    bool startsWith(string prefix) {

        trie* temp = node;;
        for(char ch:prefix){
            int index = ch-'a';
            if(temp->child[index] == NULL){
                return false;
            }
            temp = temp->child[index];
        }

        return true;
    }
};
