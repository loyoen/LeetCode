#include <stdlib.h>
//Integer to Roman
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int NumList[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string SigList[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        if(num<=0)
            return "";
        for(int i=0;i<13;i++)
        {
            if(num>=NumList[i])
                return string(SigList[i])+intToRoman(num-NumList[i]);
        }
    }
};
int main()
{
    Solution Test;
    
    cout<<Test.intToRoman(3999);
    system("pause");
    return 0;
}
