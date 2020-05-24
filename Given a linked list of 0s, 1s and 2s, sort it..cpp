Node* segregate(Node *head) {
    
    Node* temp1=head;
    Node* t1=NULL;
    int count=0,c=0;
    Node* t4=NULL;
    while(temp1!=NULL)
    {
        if(temp1->data!=NULL)
        t4=temp1;
        t1=temp1;
        temp1=temp1->next;
    }
    Node* t5=t4;
    if(t1->data==0)
    t1=t4;
    while(t5!=NULL)
    {
        if(t5->data==0)
        {
              Node* n1=new Node(0);
            n1->next=head;
            head=n1;
        }
        t5=t5->next;
    }
    t4->next=NULL;
    Node* last=t4;
    while(head->data==2 && head!=t1)
    {
        head=head->next;
        Node* n1=new Node(2);
        last->next=n1;
        last=n1;
    }
    Node* t3=head->next;
    Node* prev=head;
    while(t3!=t4)
    {
        if(t3->data==0)
        {
            prev->next=t3->next;
            t3=t3->next;
            Node* n1=new Node(0);
            n1->next=head;
            head=n1;
        }
        else if(t3->data==2)
        {
              prev->next=t3->next;
              t3=t3->next;
               Node* n1=new Node(2);
               last->next=n1;
               last=n1;
        }
        else
        {
            prev=t3;
            t3=t3->next;
        }
    }
    return head;
    
}

