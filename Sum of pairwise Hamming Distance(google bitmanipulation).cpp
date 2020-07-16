/*
Problem Description

Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.

Given an array A of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array. Return the answer modulo 1000000007.



Problem Constraints
1 <= |A| <= 200000

1 <= A[i] <= 109



Input Format
First and only argument is array A.

Output Format
Return one integer, the answer to the problem.

Example Input
Input 1:

 A = [1]
Input 2:

 A = [2, 4, 6]

Example Output
Output 1:

 0
Output 2:

 8


Example Explanation
Explanation 1:

 No pairs are formed.
Explanation 2:

 We return, f(2, 2) + f(2, 4) + f(2, 6) + f(4, 2) + f(4, 4) + f(4, 6) + f(6, 2) + f(6, 4) +

*/
//vector<vector<short> >dp;
/*
logic
Suppose the given array contains only binary numbers, i.e A[i] belongs to [0, 1].

Let X be the number of elements equal to 0, and Y be the number of elements equals to 1.

Then, sum of hamming distance of all pair of elements equals 2XY, as every pair containing one element from X and one element from Y contribute 1 to the sum.

As A[i] belongs to [0, 231 - 1] and we are counting number of different bits in each pair, we can consider all the 31 bit positions independent.

For example:
A = [2, 4, 6] = [0102, 1002, 1102]</p>

At bit position 0 (LSB): x = 3, y = 0
At bit position 1: x = 1, y = 2
At bit position 2(MSB): x = 1, y = 2

Total sum = number of pairs having different bit at each bit-position = (2 * 3 * 0) + (2 * 1 * 2) + (2 * 1 * 2) = 8

Time complexity: O(N)
Space complexity: O(1)


*/
int Solution::hammingDistance(const vector<int> &A) {
    if(A.size()<=1)
    return 0;
    long long sum=0,m=1000000007;
for(int i=0;i<32;i++)
{
    long long int x=0,y=0;
    for(int j=0;j<A.size();j++)
    {
        if(1&(A[j]>>i))
        x++;
        else
        y++;
    }
    sum=(sum+(2*x*y)%m)%m;
}
return sum;
}

