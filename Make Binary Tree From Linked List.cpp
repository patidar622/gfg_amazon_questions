void convert(Node *head, TreeNode *&root) {
    if(head==NULL)
    return;
    queue<TreeNode*>q1;
    TreeNode* t1=new TreeNode(head->data);
    root=t1;
    q1.push(t1);
    q1.push(NULL);
    Node* temp=head->next;
    while(temp!=NULL)
    {
        while(q1.front()!=NULL)
        {
            if(temp==NULL)
            break;
            TreeNode* t1=q1.front();
            q1.pop();
            TreeNode* l1=new TreeNode(temp->data);
            t1->left=l1;
            q1.push(l1);
            temp=temp->next;
            if(temp==NULL)
            break;
            TreeNode* r1=new TreeNode(temp->data);
            t1->right=r1;
            q1.push(r1);
            temp=temp->next;
        }
        if(temp==NULL)
        break;
        q1.pop();
        q1.push(NULL);
    }
}
