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
    int jump(int A[], int n) {
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                A[i] = 0;
                continue;
            }
            int min = n;
            if(A[i]+i>=n)
            {
                A[i] = 1;
                continue;
            }
            for(int j=A[i];j>=1;j--)
            {
                min = min>A[j+i]?A[j+i]:min;
                if(min==1)
                    break;
            }
            A[i] = min+1;
        }
        return A[0];
    }
};
int main()
{
    Solution Test;
    int s1[] = {2,1,3,1,4};
    //string s2 = "965";
    cout<<Test.jump(s1,5);
	
	
	system("pause");
    return 0;
}
