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
    void compuPermute(vector<int> &num, vector<vector<int> > &res, int n, vector<int> &path, int sig[])
    {
        if(path.size()==n)
        {
            res.push_back(path);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(sig[i]==0)
            {
                path.push_back(num[i]);
                sig[i] = 1;
                compuPermute(num,res,n,path,sig);
                sig[i] = 0;
                path.pop_back();
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        int sig[num.size()];
        memset(sig,0,sizeof(int)*num.size());
        vector<int> path;
        compuPermute(num,res,num.size(),path,sig);
        return res;
    }
};
int main()
{
    Solution Test;
    int iin[] = {2,3,6,7};
    vector<int> in(iin,iin+4); 
    
	vector<vector<int> > v = Test.permute(in);
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl; 
	}	
	
	system("pause");
    return 0;
}
