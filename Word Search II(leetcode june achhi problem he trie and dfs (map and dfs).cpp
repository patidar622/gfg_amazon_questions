/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally 
or vertically neighboring. The same letter cell may not be used more than once in a word.
Example:
Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
class Solution {
public:
  /*  
  map ands dfs solution but 2 test case gives tle 
  vector<string>ans;
    int dis[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void find_solution(string s,int i,int j,int k,vector<vector<char>>& board)
    {
        if(k==s.size()-1)
        {
            ans.push_back(s);
            return;
        } 
        int ch=board[i][j];
        board[i][j]='$';
        for(int i1=0;i1<4;i1++)
        {
            int new_r=i+dis[i1][0];
            int new_c=j+dis[i1][1];
            if(new_r>=0 && new_r<board.size() && new_c>=0 && new_c<board[0].size() && board[new_r][new_c]!='$' && board[new_r][new_c]==s[k+1])
            {
                find_solution(s,new_r,new_c,k+1,board);    
            }
        } 
        board[i][j]=ch;
        return;
    }
    */
    // trie solution accepted 
     int dis[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    vector<string>ans;
    struct node{
        char c;
       int end_hear;
        string s;
        node* child[26];
    };
    struct node* getNode(char c)//creating a  node
    {
        node* n1=new node;
        n1->c=c;
        n1->end_hear=0;
        n1->s="";
        for(int i=0;i<26;i++)
        {
            n1->child[i]=NULL;
        }
        return n1;
    }
    node* root=getNode('/');  //root
    
    void insert(string s)
    {
        node* curr=root;
        int index;
        for(int i=0;i<s.size();i++)
        {
            
            index=s[i]-'a';
            if(curr->child[index]==NULL)
                curr->child[index]=getNode(s[i]);
            
            curr=curr->child[index];
        }
        curr->s=s;
        curr->end_hear+=1;
    }
void find_solution(vector<vector<char>>& board,int i,int j,node* curr)
{
    int index=board[i][j]-'a';
    
    if(board[i][j]=='$' || curr->child[index]==NULL)
        return;
    
    curr=curr->child[index];
    if(curr->end_hear>0)
    {
        ans.push_back(curr->s);
        curr->end_hear-=1;
    }
    int ch=board[i][j];
    board[i][j]='$';
    
    for(int i1=0;i1<4;i1++)
        {
            int new_r=i+dis[i1][0];
            int new_c=j+dis[i1][1];
            if(new_r>=0 && new_r<board.size() && new_c>=0 && new_c<board[0].size() && board[new_r][new_c]!='$')
            {
                find_solution(board,new_r,new_c,curr);    
            }
        }
    board[i][j]=ch;
    return;
    
}
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int r=board.size();
        int c=board[0].size();
        ans.clear();
        for(int i=0;i<words.size();i++)
        {
            insert(words[i]);
        }
        
        for(int i=0;i<r;i++)
        {
            
            for(int j=0;j<c;j++)
            {
                find_solution(board,i,j,root);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
       /*
        unordered_map<char,vector<pair<int,int>> >m1;
        int n1=board.size();
        int m2=board[0].size();
        unordered_set<char>s1;
        for(int i=0;i<words.size();i++)
        {
            s1.insert(words[i][0]);
         }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(s1.find(board[i][j])!=s1.end())
                {
                    m1[board[i][j]].push_back({i,j});
                    }
            }
        }
        for(int i=0;i<words.size();i++)
        {
            if(m1.find(words[i][0])!=m1.end() && words[i].size()<=n1*m2)
            {
                for(int j=0;j<m1[words[i][0]].size();j++){
                    int i1=m1[words[i][0]][j].first;
                    int j1=m1[words[i][0]][j].second;
                find_solution(words[i],i1,j1,0,board);
                    }
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans; 
        */
    }
};
