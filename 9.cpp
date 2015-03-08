//Palindrome Number 
/*
   ** compare one by one. Pay attention to the case : 100021
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x<10)
            return true;
        long long index = 1;
        while(x>=index)
        {
            index *= 10;
        }
        index /= 10;
        long long Cnt = 10;
        while(1)
        {
            if(x<index&&(x%Cnt!=0))
                return false;
            if(x/index!=x%Cnt)
                return false;
            x %= index;
            x /= Cnt;
            index /= 100;
            if(Cnt>index)
                break;
        }
        return true;
    }
};
