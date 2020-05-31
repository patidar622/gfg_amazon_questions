class Trie {
public:
    struct TrieNode{
        char val;
        int end_hear;
        int count;
        TrieNode *child[26];
    };
    TrieNode* root;
    TrieNode* getnode(int index)
    {
        TrieNode* newNode=new TrieNode;
        newNode->val='a'+index;
        newNode->end_hear=newNode->count=0;
        for(int i=0;i<26;i++)
        {
            newNode->child[i]=NULL;
        }
        return newNode;
    }
    /** Initialize your data structure here. */
    Trie() {
        
        root=getnode('/'-'a');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr=root;
        int index;
        for(int i=0;i<word.size();i++)
        {
            index=word[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index]=getnode(index);
            curr->child[index]->count+=1;
            curr=curr->child[index];
        }
        curr->end_hear+=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr=root;
        int index;
        for(int i=0;i<word.size();i++)
        {
            index=word[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr=curr->child[index];
        }
        return (curr->end_hear>0);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        int index;
        
        for(int i=0;i<prefix.size();i++)
        {
            index=prefix[i]-'a';
            if(curr->child[index]==NULL)
                return false;
            curr=curr->child[index];
        }
        return (curr->count>0);
    }
};
