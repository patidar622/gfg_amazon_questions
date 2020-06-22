/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* merge_list(ListNode* f1,ListNode* l1)
 {
     ListNode* n1;
     if(f1==NULL)
     return l1;
     if(l1==NULL)
     return f1;
     
     if((f1)->val<=(l1)->val)
     {
         n1=f1;
         n1->next=merge_list(f1->next,l1);
     }
     else
     {
         n1=l1;
         n1->next=merge_list(f1,l1->next);
     }
     return n1;
 }
 ListNode*  find_solution(ListNode* A)
 {
     if(A==NULL || A->next==NULL)
     return A;
    ListNode* f1;
    ListNode* l1;
    f1=A;
    l1=A->next;
    ListNode* ss1;
     while(l1!=NULL)
     {
         ss1=f1;
         f1=f1->next;
         l1=l1->next!=NULL ? l1->next->next:l1->next;
     }
     
     ss1->next=NULL;
    ListNode* n1=find_solution(A);
    ListNode* n2=find_solution(f1);
    
    return merge_list(n1,n2);
 }
ListNode* Solution::sortList(ListNode* A) {
    
    return find_solution(A);
}

