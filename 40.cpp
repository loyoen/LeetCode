#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack> 
#include <string.h>
#include <algorithm> 
using namespace std;
class Solution {
public:
    void dealElem(vector<int> &candidates, vector<int> &path, vector<vector<int> > &res, int sum, int index, int target)
    {
        if(sum>target)
            return;
        if(sum==target)
        {
			res.push_back(path);
			return;
		}
		for(int i=index;i<candidates.size();)
        {
			int j=i+1;
			while(j<candidates.size()&&candidates[j]==candidates[i])
				j++;
			for(int k=0;k<j-i;k++)
			{
				for(int t=0;t<k+1;t++)
				{
					path.push_back(candidates[i]);
				}
				dealElem(candidates,path,res,sum+candidates[i]*(k+1),j,target);
				for(int t=0;t<k+1;t++)
				{
					path.pop_back();
				}
			}
			i = j;
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > ans;
        vector<int> path;
		sort(candidates.begin(),candidates.end());
        dealElem(candidates,path,ans,0,0,target);
		return ans;
    }
};
int main()
{
    Solution Test;
    int iin[] = {10,1,2,7,6,1,5};
    vector<int> in(iin,iin+7); 
    
	vector<vector<int> > v = Test.combinationSum2(in,8);
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl; 
	}	
	
	system("pause");
    return 0;
}
