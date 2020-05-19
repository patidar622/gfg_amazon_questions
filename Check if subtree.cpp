bool find_solution(Node* t,Node* s)
{
    if(t==NULL && s==NULL)
    return true;
    if((t!=NULL && s==NULL)||(t==NULL && s!=NULL))
    return false;
    
    bool flag=false;
    if(t->data==s->data)
     flag=find_solution(t->left,s->left) && find_solution(t->right,s->right);
    if(flag==true)
    return true;
    bool f1=find_solution(t->left,s);
    if(f1==true)
    return true;

    bool f2=find_solution(t->right,s);
    if(f2==true)
    return true;
    
    return false;
    
}
