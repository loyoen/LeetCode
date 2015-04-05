#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack> 
#include <string.h> 
using namespace std;
#define LEFT '('
#define RIGHT ')'
class Solution {
public:
    int findItem(int A[],int start,int end,int target)
    {
        if(start>end)
            return -1;
        if(start==end&&A[start]==target)
            return start;
        else if(start==end&&A[start]!=target)
            return -1;
        int middle = (start+end)/2;
        if(A[middle]==target)
            return middle;
        else if(A[middle]>target)
        {
			if(A[start]==target)
				return start;
            else if(A[start]>A[middle]||A[start]<target)
                return findItem(A,start+1,middle-1,target);
            else if(A[start]>target)
				return findItem(A,middle+1,end,target);
            else if(start==middle)
                return findItem(A,start+1,end,target);
        }
        else
        {
			if(A[start]==target)
				return start;
            else if(A[start]<A[middle]||A[start]>target)
                return findItem(A,middle+1,end,target);
            else if(A[start]>A[middle])
                return findItem(A,start+1,middle-1,target);
            else if(start==middle)
                return findItem(A,start+1,end,target);		
        }
    }
    int search(int A[], int n, int target) {
        int ans = findItem(A,0,n-1,target);
        return ans;
    }
};
int main()
{
    Solution Test;
   
    int a[] = {5,1,3};
    /*vector<int> v(a,a+3);
    Test.nextPermutation(v);
    for(int i=0;i<v.size();i++)
    	cout<<v[i]<<endl;
	//cout<<Test.divide(-2147483648, -3);
	*/
	cout<<Test.search(a,3,5);
	system("pause");
    return 0;
}
