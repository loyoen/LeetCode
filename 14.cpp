//Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int iLen = strs.size();
        if(iLen==0)
            return "";
        string FirstStr = strs[0];
        int iMostLen = FirstStr.length();
        if(iMostLen==0)
            return "";
        for(int i=0;i<iMostLen;i++)
        {
            char CurChar = FirstStr.at(i);
            for(int j=1;j<iLen;j++)
            {
                if(strs[j].length()<=i)
                    return strs[j];
                if(strs[j].at(i)!=CurChar)
                    return FirstStr.substr(0,i);
            }
        }
        return FirstStr;
    }
};
