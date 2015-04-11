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
    string StrAdd(string num1, string num2)
    {
        int flag = 0;
        if(num1.length()<=num2.length())
        {
            for(int i=num1.length()-1;i>=0;i--)
            {
                int ans = num1[i]-'0'+num2[i]-'0'+flag;
                num2[i] = (ans%10)+'0';
                flag = ans/10;
            }
            if(flag>0)
                return string("1")+num2;
            else
                return num2;
        }
        else
        {
            for(int i=num2.length()-1;i>=0;i--)
            {
                int ans = num1[i]-'0'+num2[i]-'0'+flag;
                num1[i] = (ans%10)+'0';
                flag = ans/10;
            }
            if(flag>0)
                return string("1")+num1;
            else
                return num1;
        }
    }
    string StrMulOneElem(string num1, char c)
    {
        int flag = 0;
        for(int i=0;i<num1.length();i++)
        {
            int ans = (num1[i]-'0')*(c-'0')+flag;
            num1[i] = (ans%10)+'0';
            flag = ans/10;
        }
        if(flag>0)
        {
            char ctmp[5];
            sprintf(ctmp,"%c",flag);
            return string(ctmp)+num1;
        }
        return num1;
    }
    string multiply(string num1, string num2) {
        string ans = "";
        for(int i=0;i<num2.length();i++)
        {
            ans += string("0");
            ans += StrMulOneElem(num1,num2[i]);
        }
        return ans;
    }
};
int main()
{
    Solution Test;
    string s1 = "476";
    string s2 = "965";
    cout<<Test.multiply(s1,s2);
	
	
	system("pause");
    return 0;
}
