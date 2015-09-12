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
    void rotate(vector<vector<int> > &matrix) {
        int iLen = matrix.size();
        int index = iLen/2 - 1;
        for(int i=index;i>=0;i--)
        {
            int thisLen = iLen-i-i;
            for(int j=i;j<thisLen-1+i;j++)
            {
                int posx = 0, posy = j-i;
                int lastvalue = matrix[posx+i][posy+i], value = -1;
                int dis = thisLen-1;
                int curindex = j-i+dis;
                while(curindex<thisLen*5-5)
                {
                    if(curindex<=dis||curindex>=4*thisLen-4)
                    {
                        posx = 0;
                        posy = curindex%(4*thisLen-4);
                    }
                    else if(curindex<2*thisLen-1)
                    {
                        posx = curindex - dis;
                        posy = dis;
                    }
                    else if(curindex<3*thisLen-2)
                    {
                        posx = dis;
                        posy = 3*(thisLen-1) - curindex;
                    }
                    else
                    {
                        posx = 4*thisLen - 4 - curindex;
                        posy = 0;
                    }
                    value = matrix[posx+i][posy+i];
                    matrix[posx+i][posy+i] = lastvalue;
                    lastvalue = value;
                    curindex += dis;
                }
            }
        }
        return;
    }
};
int main()
{
    Solution Test;
    //int iin[] = {2,3,6,7};
    //vector<int> in(iin,iin+4); 
    vector<vector<int> > v;
    int t = 5;
    for(int i=0;i<t;i++)
    {
    	vector<int> tmp;
    	for(int j=0;j<t;j++)
    	{
    		tmp.push_back(i*10+j);
    	}
    	v.push_back(tmp);
    }
	Test.rotate(v);
	
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
		cout<<endl; 
	}	
	
	system("pause");
    return 0;
}
