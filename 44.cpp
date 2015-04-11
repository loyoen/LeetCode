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
	int strFind(string s, string p,int pos=0)
	{
		if(p.length()==0)
			return pos;
		int t = s.length()-p.length()+1;
		for(int i=pos;i<t;i++)
		{
			bool isFound = true;
			for(int j=0;j<p.length();j++)
			{
				if(s[i+j]!=p[j]&&p[j]!='?')
				{
					isFound = false;
					break;
				}
			}
			if(isFound)
				return i;
		}
		return -1;
	}
    bool isMatch(const char *s, const char *p) {
        int iLen1 = strlen(s), iLen2 = strlen(p);
        int index = -1, pos = 0;
		bool hasSig = false;
        for(int i=0;i<iLen2;i++)
        {
            if(p[i]=='*')
            {
                if(index==-1)
					pos = strFind(string(s).substr(0,i-index-1),string(p).substr(index+1,i-index-1),pos);
				else
					pos = strFind(string(s),string(p).substr(index+1,i-index-1),pos);
                if(pos==-1)
                    return false;
                pos += i-index-1;
                index = i;
				hasSig = true;
            }
        }
		string ans1 = string(s).substr(pos,iLen1-pos);
		string ans2 = string(p).substr(index+1,iLen2-index-1);
		if(hasSig)
		{
			if(ans1.length()>=ans2.length()&&strFind(ans1,ans2,ans1.length()-ans2.length())==ans1.length()-ans2.length())
				return true;
			else
				return false;
		}
		else if(iLen2-index-1<=iLen1&&ans1.length()==ans2.length()&&strFind(ans1,ans2,0)==0)
            return true;
        else
			return false;
    }
};
int main()
{
    Solution Test;
    string s1 = "476";
    string s2 = "965";
    cout<<Test.isMatch("abefcdgiescdfimde","ab*cd?i*de");
	
	
	system("pause");
    return 0;
}
