#include<bits/stdc++.h>
using namespace std;
class trie{
    public:
struct TrieNode{
  char c;  
  int end_hear;
  int count;
  TrieNode* child[26];
};
TrieNode* getNode(int index)
{
    TrieNode* newNode=new TrieNode;
    newNode->c='a'+index;
    newNode->end_hear=newNode->count=0;
    for(int i=0;i<26;i++)
    {
        newNode->child[i]=NULL;
    }
    return newNode;
}
TrieNode* root;
trie(){
root=getNode('/'-'a');
}
void insert_string(string s)
{
    TrieNode* curr=root;
    int index;
    for(int i=0;i<s.size();i++)
    {
        index=s[i]-'a';
        if(curr->child[index]==NULL)
        curr->child[index]=getNode(index);
        curr=curr->child[index];
        curr->count+=1;
    }
    curr->end_hear+=1;
}
bool find_string(string s)
{
    TrieNode* curr=root;
    int index;
    for(int i=0;i<s.size();i++)
    {
        index=s[i]-'a';
        if(curr->child[index]==NULL)
        return false;
        curr=curr->child[index];
    }
    return (curr->end_hear>0);
}
};
int main()
 {
	int t;cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    trie* t1=new trie();
	    for(int i=0;i<n;i++)
	    {
	        string s;
	        cin>>s;
	        t1->insert_string(s);
	    }
	    string a;
	    cin>>a;
	    if(t1->find_string(a))
	    cout<<1<<endl;
	    else
	    cout<<0<<endl;
	}
	return 0;
}
