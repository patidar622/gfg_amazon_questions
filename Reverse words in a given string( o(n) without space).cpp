/*
Given a String of length S,
 reverse the whole string without reversing the individual words in it.
  Words are separated by dots.
Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)
Input:
2
i.like.this.program.very.much
pqr.mno
Output:
much.very.program.this.like.i
mno.pqr

*** hint***
first reverse the individual words, we get the below string.
     "i ekil siht margorp yrev hcum"
next reverse the whole string from start to end and you get the desired output.
     "much very program this like i"
*/
void find_reverse(char *s,int i,int j)
{
    while(i<=j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
}
void reverseWords(char *s) {
    
    int i=0,count=0;
    while(s[i]!='\0')
    {
        i++;
        count++;
    }
    i=0;
    while(s[i]!='\0')
    {
        int j=i;
        while(s[i]!='\0' && s[i]!='.')
        {
            i++;
        }
        find_reverse(s,j,i-1);
        i++;
    }
    find_reverse(s,0,count-1);
    i=0;
    while(s[i]!='\0')
    {
        cout<<s[i];
        i++;
    }
}

