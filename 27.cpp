#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack> 
using namespace std;
#define MAX_INT 2147483647

class Solution {
public:
	int getIndex(int dividend, int divisor, int start, int end)
	{
		if(start==end||start==end-1)
			return start;
		
	}
    int divide(int dividend, int divisor) {
        if(divisor==0)
            return MAX_INT;
        long long iDivendTmp = dividend>=0?dividend:(long long)0-(long long)dividend;
        long long iDivisorTmp =  divisor>=0?divisor:(long long)0-(long long)divisor;
        if(iDivendTmp<iDivisorTmp)
            return 0;
        long long min = 1, tmp = 0, tmp2 = iDivisorTmp, iCntDivsor = iDivisorTmp;
        while(iDivendTmp>=iCntDivsor)
        {
        	tmp2 = iCntDivsor;
            iCntDivsor += iCntDivsor;
            tmp = min;
            min += min;
        }
        long long ans = tmp + divide(iDivendTmp-tmp2,iDivisorTmp);
       	ans = ((dividend>=0&&divisor>0)||(dividend<=0&&divisor<0))?ans:0-ans;
        if(ans>MAX_INT)
        	return MAX_INT;
        return int(ans);
    }
};
int main()
{
    Solution Test;
    cout<<Test.divide(-2147483648, -3);
	system("pause");
    return 0;
}
