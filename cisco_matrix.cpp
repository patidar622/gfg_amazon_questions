#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
vector<vector<int>>swp={{0,1},{0,3},{1,2},{1,4},{2,5},{3,4},{3,6},{4,5},{4,7},
    {5,8},{6,7},{7,8}};
    //{{0,1},{0,3},{1,2},{1,4},{3,4},{3,6},{2,5},{4,5},{4,7},{6,7},{5,8},{7,8}};
int is[]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};
//0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0};
void help()
{
    string temp="123456789";
    queue<string>q;
    q.push(temp);
    int cnt=0;
    mp[temp]=0;
    
    while(!q.empty())
    {
        cnt++;
        int sz=q.size();
        while(sz--)
        {
            string a=q.front();
            q.pop();
            for(int i=0;i<swp.size();i++)
            {
                int ind=int(a[swp[i][0]]-'0');
                int jnd=int(a[swp[i][1]]-'0');
                if(is[ind+jnd])
                {
                    string tmp=a;
                    swap(tmp[swp[i][0]],tmp[swp[i][1]]);
                    if(mp.find(tmp)==mp.end())
                    {
                        mp[tmp]=cnt;
                        q.push(tmp);
                    }
                }
            }
        }
        
    }
    
    
}
int main() {
    
    int t;
    cin>>t;
    help();
    while(t--)
    {
        string s="";
        for(int i=0;i<9;i++)
        {
            char ch;
            cin>>ch;
            s+=ch;
        }
        if(mp.find(s)==mp.end())
        {
            cout<<"-1"<<endl;
        }
        else cout<<mp[s]<<endl;
        
    }
	// your code goes here
	return 0;
}
/*
python
default=(1,2,3,4,5,6,7,8,9)
swaps=[(0,1),(1,2),(3,4),(4,5),(6,7),(7,8),(0,3),(3,6),(1,4),(4,7),(2,5),(5,8)]
primes=[3,5,7,11,13,17]
all_cases={default:0}

cheak=[default]
while cheak:
    state=cheak[0]
    
    for i in swaps:
        m=i[0]
        n=i[1]
        if state[m]+state[n] in primes:
            state_lst=list(state)
            state_lst[m],state_lst[n]=state_lst[n],state_lst[m]
            new_state=tuple(state_lst)
            
        if new_state not in all_cases:
            all_cases[new_state]=all_cases[state]+1
            cheak.append(new_state)
    cheak.remove(state)        
    
t=int(input())
for i in range(t):
    input()
    a,b,c=map(int,input().split())
    d,e,f=map(int,input().split())
    g,h,i=map(int,input().split())
    case=(a,b,c,d,e,f,g,h,i)
    
    if case in all_cases:
        print(all_cases[case])
    else:
        print(-1)
*/

 //c me
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N        (3)        // matrix dimension
#define N_STATES (362880/2) // 9!/2
#define N_SOL    ((987654321)/10)

char prime[] = {
    0, /* 0 */
    1, /* 1 */
    1, /* 2 */
    1, /* 3 */
    0, /* 4 */
    1, /* 5 */
    0, /* 6 */
    1, /* 7 */
    0, /* 8 */
    0, /* 9 */
    0, /* 10 */
    1, /* 11 */
    0, /* 12 */
    1, /* 13 */
    0, /* 14 */
    0, /* 15 */
    0, /* 16 */
    1, /* 17 */
    0, /* 18 */
    1  /* 19 */
};
int tenpow[] = {
    100000000,  /* 0 (10^8) */
    10000000,   /* 1 (10^7) */
    1000000,    /* 2 (10^6) */
    100000,     /* 3 (10^5) */
    10000,      /* 4 (10^4) */
    1000,       /* 5 (10^3) */
    100,        /* 6 (10^2) */
    10,         /* 7 (10^1) */
    1           /* 8 (10^0) */
};

int  board[N*N];
char visited[N_SOL];
int  queue[N_STATES];
int  head, tail;
int  current_index;

void moveit(int i, int j)
{
    int diff = board[j]-board[i];
    int next_index = current_index + diff*tenpow[i] - diff*tenpow[j];
    if ( visited[(next_index)/10] == 0 ) {
        visited[(next_index)/10] = visited[(current_index)/10]+1;
        queue[tail++] = next_index;
    }

}

void scramble_states() {

    int i;
    int state_index;
    
    head = 0;
    while ( head < tail ) {
        // fill board
        current_index = state_index = queue[head];
        for ( i=8; i >= 0; state_index /= 10, i-- )
            board[i] = state_index%10;

        if ( prime[board[0]+board[1]] ) moveit(0, 1);
        if ( prime[board[0]+board[3]] ) moveit(0, 3);
        if ( prime[board[1]+board[2]] ) moveit(1, 2);
        if ( prime[board[1]+board[4]] ) moveit(1, 4);
        if ( prime[board[2]+board[5]] ) moveit(2, 5);
        if ( prime[board[3]+board[4]] ) moveit(3, 4);
        if ( prime[board[3]+board[6]] ) moveit(3, 6);
        if ( prime[board[4]+board[5]] ) moveit(4, 5);
        if ( prime[board[4]+board[7]] ) moveit(4, 7);
        if ( prime[board[5]+board[8]] ) moveit(5, 8);
        if ( prime[board[6]+board[7]] ) moveit(6, 7);
        if ( prime[board[7]+board[8]] ) moveit(7, 8);
               // move head
        head++;
    }
}

int main()
{
    int test_cases;
    int state_index;
    int tmp;

    // init data
    tail = 0;
    queue[tail++] = 123456789;
    visited[123456789/10] = 1;
    // generate reachable configurations from goal
    scramble_states();
    // solve input
    fscanf(stdin, "%d", &test_cases);
    for ( int i = 0; i < test_cases; i++ ) {
        state_index = 0;
        for ( int j = 0; j < N*N; j++ ) {
            fscanf(stdin, "%d", &tmp);
            state_index = (state_index << 3) + (state_index << 1) + tmp;
        }
        printf("%d\n", visited[state_index/10] - 1);
    }
    return 0;
}

