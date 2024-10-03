//time: O(n) space: O(n)
class TrieNode {
public:
    vector<TrieNode*> next;
    bool isWord;
    TrieNode() {
        next.resize(26);
        isWord = false;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(curr -> next[c - 'a'] == NULL) {
                curr -> next[c - 'a'] = new TrieNode();
            }
            curr = curr -> next[c - 'a'];
        }
        curr -> isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(curr -> next[c - 'a'] == NULL) {
                return false;
            }
            curr = curr -> next[c - 'a'];
        }
        return curr -> isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if(curr -> next[c - 'a'] == NULL) {
                return false;
            }
            curr = curr -> next[c - 'a'];
        }
        return true;
    }
};