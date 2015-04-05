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
    int longestValidParentheses(string s) {
        int *sig = (int*)malloc(sizeof(int)*(s.length()+1));
        memset(sig,0,sizeof(int)*(s.length()+1));
        for(int i=0;i<s.length();i++)
        {
            if(s.at(i)==RIGHT)
            {
                if(i==0||i-sig[i-1]-1<0)
                    continue;
                if(s.at(i-sig[i-1]-1)==LEFT)
                {
                    sig[i] = sig[i-1] + 2;
                    if(i-sig[i-1]-2>=0)
                        sig[i] += sig[i-sig[i-1]-2];
                }
                else
                    sig[i] = 0;
            }
            else
            {
                sig[i] = 0;
            }
        }
        int max = 0;
        for(int i=0;i<s.length();i++)
            max = max>sig[i]?max:sig[i];
        return max;
    }
};
int main()
{
    Solution Test;
    /* 
    int a[] = {1,3,2};
    vector<int> v(a,a+3);
    Test.nextPermutation(v);
    for(int i=0;i<v.size();i++)
    	cout<<v[i]<<endl;
	//cout<<Test.divide(-2147483648, -3);
	*/
	cout<<Test.longestValidParentheses(")");
	system("pause");
    return 0;
}
