//https://leetcode.com/problems/implement-trie-prefix-tree/

//TrieImplementation


class TrieNode{
    public : 
    int string;
    bool isEnd;
    TrieNode* children[26];
    TrieNode()
    {
        string = 0;
        isEnd = false;
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++)
        {
            int childIndx = word[i] - 'a';
            if(curr->children[childIndx] == NULL)
                curr->children[childIndx] = new TrieNode();
            curr = curr->children[childIndx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++)
        {
            int childIndx = word[i] - 'a';
            if(curr->children[childIndx] == NULL)
                return false;
            curr = curr->children[childIndx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(int i=0;i<prefix.size();i++)
        {
            int childIndx = prefix[i] - 'a';
            if(curr->children[childIndx] == NULL)
                return false;
            curr = curr->children[childIndx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */