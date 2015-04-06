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
    void solveSudoku(vector<vector<char> > &board) {
        int sig[27][9] = {0};
        vector<int> emptyPos;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='.')
                {
                    emptyPos.push_back(i);
                    emptyPos.push_back(j);
                    continue;
                }
                sig[i][board[i][j]-'0'-1] += 1;
                sig[j+9][board[i][j]-'0'-1] += 1;
                sig[(i/3)*3+j/3+18][board[i][j]-'0'-1] += 1;
            }
        }
        
        stack<int> sElems;
        int value = -1;
        for(int i=0;i<emptyPos.size();)
        {
            int x = emptyPos[i], y = emptyPos[i+1];
            bool isFilledSuc = false;
            for(int j=value+1;j<9;j++)
            {
                if(sig[x][j]==0&&sig[y+9][j]==0&&sig[(x/3)*3+y/3+18][j]==0)
                {
                    sElems.push(x);
                    sElems.push(y);
                    sElems.push(j);
                    sig[x][j] += 1;
                    sig[y+9][j] += 1;
                    sig[(x/3)*3+y/3+18][j] += 1;
                    board[x][y] = '0'+1+j;
                    isFilledSuc = true;
                    break;
                }
            }
            if(isFilledSuc)
            {
                i+=2;
                value = -1;
                continue;
            }
            value = sElems.top();
            sElems.pop();
            y = sElems.top();
            sElems.pop();
            x = sElems.top();
            sElems.pop();
            sig[x][value] -= 1;
            sig[y+9][value] -= 1;
            sig[(x/3)*3+y/3+18][value] -= 1;
            i-=2;
            if(i<0)
                break;
        }
        return;
    }
};
int main()
{
    Solution Test;
    
	char t1[] = {'5','3','.','.','7','.','.','.','.'};
	char t2[] = {'6','.','.','1','9','5','.','.','.'};
	char t3[] = {'.','9','8','.','.','.','.','6','.'};
	char t4[] = {'8','.','.','.','6','.','.','.','3'};
	char t5[] = {'4','.','.','8','.','3','.','.','1'};
	char t6[] = {'7','.','.','.','2','.','.','.','6'};
	char t7[] = {'.','6','.','.','.','.','2','8','.'};
	char t8[] = {'.','.','.','4','1','9','.','.','5'};
	char t9[] = {'.','.','.','.','8','.','.','7','9'};
    vector<vector<char> > v;
    
    vector<char> tt1(t1,t1+9);
    v.push_back(tt1);

	vector<char> tt2(t2,t2+9);
    v.push_back(tt2);

	vector<char> tt3(t3,t3+9);
    v.push_back(tt3);

	vector<char> tt4(t4,t4+9);
    v.push_back(tt4);

	vector<char> tt5(t5,t5+9);
    v.push_back(tt5);

	vector<char> tt6(t6,t6+9);
    v.push_back(tt6);

	vector<char> tt7(t7,t7+9);
    v.push_back(tt7);

	vector<char> tt8(t8,t8+9);
    v.push_back(tt8);

	vector<char> tt9(t9,t9+9);
    v.push_back(tt9);
	Test.solveSudoku(v);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<v[i][j]<<" ";
		cout<<endl; 
	}	
	system("pause");
    return 0;
}
