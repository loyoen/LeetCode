#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack> 
#include <string.h> 
using namespace std;
class Solution {
public:
    int getNext(vector<int> &num, int start, int end, int &max)
    {
        if(start>=end)
            return num[start];
        if(start+1==end)
        {
            if(num[start]<num[end])
            {
                swap(num[start],num[end]);
                return 1;
            }
            else
            {
                max = num[start];
                return 0;
            }
        }
        int ans = getNext(num,start+1,end,max);
        if(ans==1)
            return 1;
        if(num[start]>=max)
        {
            max = num[start];
            return 0;
        }
        int firstBiger = max+1;
        int index = start;
        for(int i=start+1;i<=end;i++)
        {
            if(num[i]>num[start])
            {
                if(firstBiger>=num[i])
                {
                    firstBiger = num[i];
                    index = i;
                }
            }
        }
        swap(num[start],num[index]);
        for(int i=start+1;i<(end-start)/2+start+1;i++)
        {
            swap(num[i],num[end-i+start+1]);
        }
        return 1;
    }
    void nextPermutation(vector<int> &num) {
    	int max = 0;
        int ans = getNext(num,0,num.size()-1,max);
        if(ans==1)
            return;
        int iLen = num.size();
        for(int i=0;i<iLen/2;i++)
            swap(num[i],num[iLen-1-i]);
        return;
    }
};
int main()
{
    Solution Test;
    int a[] = {2,3,1,3,3};
    vector<int> v(a,a+5);
    Test.nextPermutation(v);
    for(int i=0;i<v.size();i++)
    	cout<<v[i]<<endl;
	//cout<<Test.divide(-2147483648, -3);
	system("pause");
    return 0;
}
