/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* ans=NULL;
    ListNode* last=NULL;
    ListNode* curr=A;
    while(curr!=NULL)
    {
         ListNode* n1=new ListNode(curr->val);
        if(ans==NULL)
        {
            ans=n1;
            last=n1;
        }
        else if(last->val<=curr->val)
        {
            last->next=n1;
            last=n1;
        }
        else if(ans->val>=curr->val)
        {
           
            n1->next=ans;
            ans=n1;
        }
        else
        {
            ListNode* n2=ans;
            while(n2!=NULL && n2->next!=NULL && n2->next->val<curr->val)
            {
                n2=n2->next;
            }
            n1->next=n2->next;
            n2->next=n1;
        }
        curr=curr->next;
    }
    return ans;
    
}

