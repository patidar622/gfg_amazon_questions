/*
The cost of stock on each day is given in an array A[] of size N.
 Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.


*/
void stockBuySell(int price[], int n) {
    int start=0;
    int last=-1;
    vector<pair<int,int> >ans;
    for(int i=1;i<n;i++)
    {
        if(last==-1 && price[start]>=price[i])
        {
            start=i;
            last=-1;
        }
        else if(last!=-1 && price[last]>price[i])
        {
            ans.push_back({start,last});
            start=i;
            last=-1;
        }
        else if(last==-1 && price[start]<price[i])
        {
            last=i;
        }
        else if(last!=-1 && price[last]<=price[i])
        {
            last=i;
        }
    }
    if(last!=-1)
    {
        ans.push_back({start,last});
    }
    if(ans.size()!=0)
    {
        for(auto i:ans)
        {
            cout<<"(";
            cout<<i.first<<" "<<i.second<<")"<<" ";
        }
        cout<<endl;
    }
    else
    cout<<"No Profit"<<endl;
    ans.clear();
}
