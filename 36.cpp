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
    bool checkNum(vector<char> nums)
    {
        int sig[9] = {0};
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!='.')
                sig[nums[i]-1-'0'] += 1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!='.'&&sig[nums[i]-1-'0']>1)
                return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i=0;i<board.size();i++)
        {
            if(!checkNum(board[i]))
                return false;
        }
        for(int i=0;i<board.size();i++)
        {
            vector<char> vTmp;
            for(int j=0;j<board.size();j++)
                vTmp.push_back(board[j][i]);
            if(!checkNum(vTmp))
                return false;
        }
        for(int i=0;i<board.size();i++)
        {
            vector<char> vTmp;
            for(int j=0;j<board.size();j++)
            {
                vTmp.push_back(board[(i/3)*3+j/3][(i%3)*3+j%3]);
            }
            if(!checkNum(vTmp))
                return false;
        }
        return true;
    }
};
int main()
{
    Solution Test;
    
    //char t[][] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"}
    int a[] = {5,1,3};
    vector<vector<char> > v;
    vector<char> tmp;
    tmp.push_back('.');
    for(int i=1;i<9;i++)
    {
    	tmp.push_back(9-i+'0');
    }
    v.push_back(tmp);
    for(int i=2;i<=9;i++)
    {
    	vector<char> tt;
    	tt.push_back(i+'0');
    	for(int j=0;j<8;j++)
    		tt.push_back('.');
    	v.push_back(tt);
    }
    /*Test.nextPermutation(v);
    for(int i=0;i<v.size();i++)
    	cout<<v[i]<<endl;
	//cout<<Test.divide(-2147483648, -3);
	*/
	cout<<Test.isValidSudoku(v);
	system("pause");
    return 0;
}
