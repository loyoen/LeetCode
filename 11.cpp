#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        int MostContainer = 0;
        int iLen = height.size();
        int iLastPos = iLen-1;
        for(int i=0;i<iLen;)
        {
        	cout<<i<<" "<<iLastPos<<endl;
            if(i>=iLastPos)
                break;
            if(height[i]<=height[iLastPos])
            {
                int CurContainer = height[i]*(iLastPos-i);
                MostContainer = MostContainer>CurContainer?MostContainer:CurContainer;
                i++;
            }
            else
            {
                int CurContainer = height[iLastPos]*(iLastPos-i);
                MostContainer = MostContainer>CurContainer?MostContainer:CurContainer;
                iLastPos--;
            }
            
        }
        return MostContainer;
    }
};
int main()
{
    Solution Test;
    vector<int> iv;
    iv.push_back(1);
    iv.push_back(2);
    iv.push_back(4);
    iv.push_back(3);
    cout<<Test.maxArea(iv);
    system("pause");
    return 0;
}
