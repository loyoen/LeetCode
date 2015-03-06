#ZigZag Conversion 
class Solution:
    # @return a string
    def convert(self, s, nRows):
        ConvList = []
        if nRows==1:
            return s
        for i in range(0,nRows):
            tempList = ""
            ConvList.append(tempList)
        Index = 0
        swit = 0 
        for i in range(0,len(s)):
            if swit==0:
                ConvList[Index]+=s[i]
                Index += 1
                if Index>=nRows:
                    Index -= 2
                    swit = 1
            else:
                ConvList[Index]+=s[i]
                Index -= 1
                if Index<0:
                   Index += 2
                   swit = 0
        AnsStr = ""
        for i in range(0,nRows):
            AnsStr += ConvList[i]
        return AnsStr
Test = Solution()
print Test.convert("abcd", 2)
