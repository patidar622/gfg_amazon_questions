int getId(int M[MAX][MAX], int n)
{
   int cel=0;
   for(int i=1;i<n;i++)
   {
       if(M[cel][i]==1)
       {cel=i;
      }
   }
   int count=0;
   for(int i=0;i<n;i++)
   {
       if(i!=cel && M[cel][i]==0 && M[i][cel]==1)
       count++;
   }
   if(count==n-1)
   return cel;
   return -1;
}
