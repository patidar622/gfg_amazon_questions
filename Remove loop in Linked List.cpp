void removeTheLoop(Node *head)
{
       Node* temp1=head;
       Node* temp2=head;
    while(temp1!=NULL && temp2!=NULL && temp2->next!=NULL)
    {
        temp1=temp1->next;
        temp2=(temp2->next)->next;
        if(temp1==temp2)
        break;
    }
  if(temp1==NULL || temp2==NULL)
  return;
    if(temp1==temp2){
        temp1=head;
    while(temp1->next!=temp2->next)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp2->next=NULL;
    }
}
