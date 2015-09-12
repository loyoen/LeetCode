#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack> 
#include <string.h> 
using namespace std;
class Solution {
private:
	int fillall;
public:
    void judge(int colDeny, int leftDeny, int rightDeny, int& totalNum)
    {
        if(colDeny == fillall)
        {
            totalNum ++;
            return;
        }
        int allowPos = fillall & (~(colDeny | leftDeny | rightDeny));
        while(allowPos > 0)
        {
            int pos = allowPos & (~allowPos + 1);
            allowPos -= pos;
            judge(colDeny|pos, (leftDeny|pos)>>1, (rightDeny|pos)<<1, totalNum);
        }
    }
    int totalNQueens(int n) {
        fillall = 0;
        for(int i=0;i<n;i++)
        {
            fillall = (fillall<<1)+1;
        }
        int totalNum = 0;
        judge(0,0,0,totalNum);
        return totalNum;
    }
};
int main()
{
    Solution Test;
	
	cout << Test.totalNQueens(4); 
	system("pause");
    return 0;
}
