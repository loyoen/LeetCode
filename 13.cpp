//Roman to Integer 
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        string SigLine = "IVXLCDM";
        int NumVal[] = {1,5,10,50,100,500,1000};
        int iLen = s.length();
        if(iLen<=0)
            return 0;
        if(iLen==1)
        {
            int pos = SigLine.find(s);
            if(pos==-1)
                return 0;
            else
                return NumVal[pos];
        }
        string s1 = s.substr(0,1);
        string s2 = s.substr(1,1);
        int pos1 = SigLine.find(s1);
        int pos2 = SigLine.find(s2);
        if(pos1==-1||pos2==-1)
            return 0;
        if(NumVal[pos1]<NumVal[pos2])
            return romanToInt(s.substr(1,iLen-1))-NumVal[pos1];
        else
            return romanToInt(s.substr(1,iLen-1))+NumVal[pos1];
    }
};
int main()
{
    Solution Test;
    
    cout<<Test.romanToInt("MMMCMXCIX");
    system("pause");
    return 0;
}
