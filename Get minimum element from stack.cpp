/*
The structure of the class is as follows
class _stack{
stack<int> s;

int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin()
{
    if(s.empty())
    return -1;
    return minEle;
   //Your code here
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.empty())
    return -1;
   int i1=s.top();
   s.pop();
   if(i1>=minEle)
   return i1;
   else
   {
       int i=minEle;
       minEle=2*minEle-i1;
       return i;
   }
}

/*push element x into the stack*/
void _stack::push(int x)
{
  if(s.empty())
  {
      s.push(x);
      minEle=x;
      return;
  }
  if(x>=minEle)
  s.push(x);
  else
  {
      int temp=2*x-minEle;
      minEle=x;
      s.push(temp);
  }
  return;
}

