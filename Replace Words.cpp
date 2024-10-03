//time: O(n) space: O(n)
class Solution {
    class TrieNode {
    public:
        vector<TrieNode*> next;
        bool isWord;
        TrieNode() {
            isWord = false;
            next.resize(26);
        }
    };
    TrieNode* root;
    void makeTrie(vector<string>& dictionary) {
        for(string s : dictionary) {
            TrieNode* curr = root;
            for(int i = 0; i < s.length(); i++) {
                char c = s[i];
                if(curr -> next[c-'a'] == NULL)
                curr -> next[c-'a'] = new TrieNode();
                curr = curr -> next[c-'a'];
            }
            curr -> isWord = true;
        }
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();
        makeTrie(dictionary);
        string result = "";
        TrieNode* curr = root;
        string word = "";
        for(int i = 0; i < sentence.length(); i++) {
            cout<<"curr: "<<sentence[i]<<endl;
            if(sentence[i] == ' ') {
                result += word + " ";
                word = "";
                curr = root;
            }
            else {
                if(curr -> next[sentence[i] - 'a'] == NULL) {
                    result += word;
                    word = "";
                    curr = root;
                    while(sentence[i] != ' ' && i < sentence.length()) {
                        result += sentence[i];
                        i++;
                    }
                    if(sentence[i] == ' ') result += " ";
                }
                else {
                    word += sentence[i];
                    curr = curr -> next[sentence[i] - 'a'];
                    if(curr -> isWord == true) {
                        cout<<sentence[i]<<endl;
                        result += word;
                        word = "";
                        curr = root;
                        while(sentence[i] != ' ' && i < sentence.length()) {
                            i++;
                        }
                        if(sentence[i] == ' ') result += " ";
                        cout<<result<<endl;
                    }
                }
            }
        }
        return result += word;
    }
};