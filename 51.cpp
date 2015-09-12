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
    bool judgeValue(int i,int j, int n, int rows[], int coums[], int lines1[], int lines2[])
    {
        return (rows[i]==0&&coums[j]==0&&lines1[i-j+n-1]==0&&lines2[i+j]==0);
    }
    void setValue(int i,int j, int value, int n, int rows[], int coums[], int lines1[], int lines2[])
    {
        rows[i] = value;
        coums[j] = value;
        lines1[i-j+n-1] = value;
        lines2[i+j] = value;
    }
    vector<vector<string> > solveNQueens(int n) {
        int i=0;
        vector<int> myStack;
        int lastpos = -1;
        int rows[n], coums[n], lines1[2*n-1], lines2[2*n-1];
        memset(rows,0,n*sizeof(int));
        memset(coums,0,n*sizeof(int));
        memset(lines1,0,(2*n-1)*sizeof(int));
        memset(lines2,0,(2*n-1)*sizeof(int));
        vector<vector<string> > res;
        while(i<n&&i>=0)
        {
            bool isfound = false;
            for(int j=lastpos+1;j<n;j++)
            {
                if(judgeValue(i,j,n,rows,coums,lines1,lines2))
                {
                    myStack.push_back(j);
                    setValue(i,j,1,n,rows,coums,lines1,lines2);
                    isfound = true;
                    break;
                }
            }
            if(isfound)
            {
                i++;
                if(i==n)
                {
                    vector<string> thisAns;
                    for(int iter = 0;i<myStack.size();iter++)
                    {
                        char ans[n+1];
                        memset(ans,'.',n+1);
                        ans[iter] = 'Q';
                        ans[n] = '\0';
                        thisAns.push_back(string(ans));
                    }
                    res.push_back(thisAns);
                    isfound = false;
                }
            }
            if(!isfound)
            {
                i--;
                if(!myStack.empty())
                {
                    int CurDone = myStack.size()-1;
                    lastpos = myStack[CurDone];
                    setValue(CurDone,lastpos,0,n,rows,coums,lines1,lines2);
					myStack.pop_back();    
                }
                else
                    break;
            }
            else
                i++;
        }
		return res;
    }
};
int main()
{
    Solution Test;
    
    int t = 5;
    
	vector<vector<string> > v = Test.solveNQueens(4);
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<endl;
		cout<<endl;
	}
	
	
	system("pause");
    return 0;
}
