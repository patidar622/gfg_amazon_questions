/*
o(n) time and o(1) space
*/
Node *copyList(Node *head) {
    if(head==NULL)
    return head;
    
    Node *temp=head;
    Node *n2=NULL;
    while(temp!=NULL)
    {
        
        Node *n1=new Node(temp->data);
        n2=temp->next;
         temp->next=n1;
        n1->next=n2;
        temp=n2;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->arb!=NULL)
        temp->next->arb=temp->arb->next;
        temp=temp->next->next;
    }
    temp=head;
    Node *temp1=temp->next;
    Node *root=temp1;
    while(temp!=NULL && temp1!=NULL)
    {
        temp->next=temp->next != NULL ? temp->next->next : temp->next;
        temp1->next=temp1->next!=NULL ? temp1->next->next : temp1->next;
        temp=temp->next;
        temp1=temp1->next;
    }
    return root;
}
/*
o(n) time and o(n) space with hash table
*/
 Node* find_solution(Node* head,map<Node*,Node*>&m1)
{
    if(head==NULL)
    return NULL;
    
    Node* n1=new Node(head->data);
    m1[head]=n1;
    n1->next=find_solution(head->next,m1);
    return n1;
}
Node *copyList(Node *head) {
    map<Node*,Node*>m1;
    Node* n1=find_solution(head,m1);
    for(auto i:m1)
    {
        i.second->arb=m1[i.first->arb];
    }
    return n1;
}
