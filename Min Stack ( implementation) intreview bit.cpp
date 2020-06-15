int min_el;
 stack<int>s1;


MinStack::MinStack() {
    min_el=-1;
    while(!s1.empty())
    {
        s1.pop();
    }
}

void MinStack::push(int x) {
    if(s1.empty())
    {s1.push(x);
    min_el=x;
        return;
    }
    else
    {
        if(x>=min_el)
        s1.push(x);
        else
        {
            s1.push(2*x-min_el);
            min_el=x;
        }
    }
    
}

void MinStack::pop() {
    if(s1.empty())
    return;
    
    if(s1.top()>=min_el)
    s1.pop();
    else
    {
        min_el=2*min_el-s1.top();
        s1.pop();
    }
}

int MinStack::top() {
    if(s1.empty())
    return -1;
    
    
    if(s1.top()>=min_el)
    return s1.top();
    else
    return min_el;
}

int MinStack::getMin() {
    if(s1.empty())
    return -1;
    
    return min_el;
}


