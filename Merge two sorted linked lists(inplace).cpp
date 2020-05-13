Node* find_solution(Node* head1,Node* head2)
{
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    
    if(head1->data>head2->data)
    swap(head1,head2);
    Node* temp1=head1;
    Node* temp2=head2;
    Node* prev=NULL;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data>temp2->data)
        {
            Node* t2=temp2->next;
            prev->next=temp2;
            temp2->next=temp1;
            prev=temp2;
            temp2=t2;
        }
        else{
        prev=temp1;
        temp1=temp1->next;
        }
    }
    if(temp1==NULL)
    {
        prev->next=temp2;
    }
    return head1;
}

Node* sortedMerge(Node* head1,   Node* head2)
{
    return find_solution(head1,head2);
}
