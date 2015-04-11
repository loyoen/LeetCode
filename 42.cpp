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
    int trap(int A[], int n) {
        int i = 0, index = i+1;
        int totalCnt = 0;
        int cnt = 0;
        int max = 0;
        int *container = (int*)malloc(sizeof(int)*n);
        memset(container,0,sizeof(int)*n);
        while(i<n)
        {
            cnt = 0;
            int min = A[max]>A[i]?A[i]:A[max];
            for(int j=i-1;j>max;j--)
            {
                if(A[j]<min)
                    cnt += min-A[j];
                else
                {
					cnt += container[j];
					break;
				}
            }
            container[i] = cnt;
            if(A[i]>=A[max])
            {
                max = i;
                totalCnt += cnt;
				container[i] = 0;
            }
            i++;
        }
        return totalCnt + container[n-1];
    }
};
int main()
{
    Solution Test;
    int iin[] = {0,1,0,2,1,0,1,3,2,1,2,1,3};
    cout<<Test.trap(iin,13);
	
	
	system("pause");
    return 0;
}
