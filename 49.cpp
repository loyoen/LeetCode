#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <stack> 
#include <map>
#include <string.h> 
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,int> Ana;
        map<string,int>::iterator iter;
        vector<string> res;
        for(int i=0;i<strs.size();i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            iter = Ana.find(tmp);
            if(iter==Ana.end())
            {
                Ana.insert(pair<string,int>(tmp,i));
            }
            else
            {
                if(iter->second==-1)
                    res.push_back(strs[i]);
                else
                {
                    res.push_back(strs[iter->second]);
                    iter->second = -1;
                    res.push_back(strs[i]);
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution Test;
    //int iin[] = {2,3,6,7};
    //vector<int> in(iin,iin+4); 
    vector<string> v;
    v.push_back("den");
    v.push_back("eat");
    v.push_back("ate");
    v.push_back("and");
    v.push_back("tea");
    /*int t = 5;
    for(int i=0;i<t;i++)
    {
    	vector<int> tmp;
    	for(int j=0;j<t;j++)
    	{
    		tmp.push_back(i*10+j);
    	}
    	v.push_back(tmp);
    }
    */
	vector<string> ans = Test.anagrams(v);
	
	for(int i=0;i<ans.size();i++)
	{
		/*for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
			*/
		cout<<ans[i]<<endl; 
	}	
	
	system("pause");
    return 0;
}
