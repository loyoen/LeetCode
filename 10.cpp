//Regular Expression Matching
/*
   * compare recursively and each time the last element should be taken into consideration
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int lenS = strlen(s), lenP = strlen(p);
        if(lenS==0&&lenP>0)
        {
            for(int i=0;i<lenP-1;i++)
            {
                if(p[i]!='*'&&p[i+1]!='*')
                    return false;
            }
            if(p[lenP-1]!='*')
                return false;
        }
        else if(lenS>0&&lenP==0)
            return false;
        else if(lenS==0&&lenP==0)
            return true;
        
        if(s[lenS-1]!=p[lenP-1]&&p[lenP-1]!='.'&&p[lenP-1]!='*')
        	return false;
        if(s[0]!=p[0]&&p[0]!='.')
        {
            if(lenP<=1)
                return false;
            if(p[1]!='*')
                return false;
            return isMatch(s,p+2);
        }
        else
        {
            if(lenP<=1&&lenS<=1)
                return true;
            else if(lenP<=1&&lenS>1)
                return false;
            if(p[1]=='*')
            {
                if(isMatch(s+1,p+2)||isMatch(s,p+2)||isMatch(s+1,p))
                	return true;
                else
                	return false;
            }
            else
                return isMatch(s+1,p+1);
        }
    }
};
int main()
{
    Solution Test;
    cout<<Test.isMatch("ab",".*");
    system("pause");
    return 0;
}
