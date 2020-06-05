/*
Note: Try to solve the problem without using any extra memory.
ans o(n) time
*/
Node* find_solution(Node* head1)
{
    Node* temp=NULL;
    while(head1!=NULL)
    {
        Node* n1=head1->next;
        head1->next=temp;
        temp=head1;
        head1=n1;
    }
    return temp;
}
void rearrange(struct Node *odd)
{
    Node* head=odd;
    Node* head1=odd->next;
    Node* h1=head;
    Node* h2=head1;
    while(head!=NULL && head1!=NULL)
    {
        head->next=head->next!=NULL ? head->next->next:head->next;
        head1->next=head1->next!=NULL ? head1->next->next:head1->next;
        
        head=head->next;
        head1=head1->next;
    }
    head=h1;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head1=h2;
    head->next=find_solution(head1);
}

