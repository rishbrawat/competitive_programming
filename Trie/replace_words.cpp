class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    void insert(TrieNode* root, string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (!curr->children[c - 'a']) {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }

    string findRoot(TrieNode* root, string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for (char c : word) {
            if (!curr->children[c - 'a']) break;
            curr = curr->children[c - 'a'];
            prefix += c;
            if (curr->isEnd) return prefix;
        }
        return word;
    }

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (string& word : dictionary) {
            insert(root, word);
        }

        stringstream ss(sentence);
        string word, result = "";
        while (ss >> word) {
            if (!result.empty()) result += " ";
            result += findRoot(root, word);
        }
        return result;
    }
};