/*
Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Your task is to complete the function tour() which returns an integer denoting the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity).

Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.
*/
/*
bool find_solution(petrolPump p[],int n,int i1)
{
    int p1=0,i=i1;
    do
    {
       p1+=p[i].petrol;
       p1-=p[i].distance;
       if(p1<0)
       return false;
       i=(i+1)%n;
    }while(i!=i1);
    return true;
}*/
int tour(petrolPump p[],int n)
{
    
    int start=0,pet=0,cap=0;
    for(int i=0;i<n;i++)
    {
        cap+=p[i].petrol-p[i].distance;
        if(cap<0)
        {
            start=i+1;
            pet+=cap;
            cap=0;
        }
    }
    return cap+pet>0?start:-1;
    /*
   queue<int>q1;
   for(int i=0;i<n;i++)
   {
       if(p[i].petrol>=p[i].distance)
       q1.push(i);
   }
   while(!q1.empty())
   {
       int i1=q1.front();q1.pop();
       if(find_solution(p,n,i1))
        return i1;
   }
   return -1;
   */
}

