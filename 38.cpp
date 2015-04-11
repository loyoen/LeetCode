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
    string countAndSay(int n) {
        string sTmp = "1";
        char NumToStr[100] = {0};
        for(int i=1;i<n;i++)
        {
            int cnt = 1;
            string ans = "";
            for(int j=0;j<sTmp.size();j++)
            {
                if(j+1<sTmp.size()&&sTmp.at(j)==sTmp.at(j+1))
                    cnt++;
                else
                {
                    sprintf(NumToStr,"%d",cnt);
                    ans += string(NumToStr);
                    if(j+1>=sTmp.size())
                    	sprintf(NumToStr,"%d",j);
                    else
                    	sprintf(NumToStr,"%d",j+1);
                    ans += string(NumToStr);
                    cnt = 1;
                    
                }
            }
            sTmp = ans;
        }
        return sTmp;
    }
};
int main()
{
    Solution Test;
    /* 
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
    */
    
	cout<<Test.countAndSay(3);
	/*
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<v[i][j]<<" ";
		cout<<endl; 
	}	
	*/
	system("pause");
    return 0;
}
