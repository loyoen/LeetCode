#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack> 
#include <string.h>
#include <algorithm> 
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int index = 0;
        for(int i=0;i<n;i++)
        {
            if(A[i]==i+1||A[i]<=0)
                continue;
            int tmp1 = A[i],tmp2;
            while(tmp1-1>=0&&tmp1-1<n&&A[tmp1-1]!=tmp1)
            {
                tmp2 = A[tmp1-1];
                A[tmp1-1] = tmp1;
                tmp1 = tmp2;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};
int main()
{
    Solution Test;
    int iin[] = {3,4,2,1};
    cout<<Test.firstMissingPositive(iin,4);
	
	
	system("pause");
    return 0;
}
