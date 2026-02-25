class Trie {
private:
    struct Node {
        Node* links[26] = {nullptr};
        bool isEnd = false;
        
        bool containsKey(char ch) { return links[ch - 'a'] != nullptr; }
        void put(char ch, Node* node) { links[ch - 'a'] = node; }
        Node* get(char ch) { return links[ch - 'a']; }
        void setEnd() { isEnd = true; }
        bool getEnd() { return isEnd; }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return true;
    }
};