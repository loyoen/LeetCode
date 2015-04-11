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
    void dealElem(vector<int> &candidates, vector<int> &path, vector<vector<int> > &res, int sum, int index, int target)
    {
        if(sum>target)
            return;
        if(sum==target)
            res.push_back(path);
        for(int i=index;i<candidates.size();i++)
        {
            path.push_back(candidates[i]);
            dealElem(candidates,path,res,sum+candidates[i],i,target);
            path.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ans;
        vector<int> path;
        dealElem(candidates,path,ans,0,0,target);
        return ans;
    }
};
int main()
{
    Solution Test;
    int iin[] = {2,3,6,7};
    vector<int> in(iin,iin+4); 
    
	vector<vector<int> > v = Test.combinationSum(in,7);
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl; 
	}	
	
	system("pause");
    return 0;
}
