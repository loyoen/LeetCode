#Longest Substring Without Repeating Characters 
'''
    use Dict to keep the latest position of every character. 
'''
class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        DictPos = {}
        maxLen = 0
        CurLen = 0
        for index in range(0,len(s)):
            try:
                LastPos = DictPos[s[index]]
                if index-LastPos > CurLen:
                    CurLen += 1
                #CurLen = min(index-LastPos,CurLen)
            except:
                LastPos = -1
                CurLen += 1
            #print CurLen
            thisLen = min(CurLen,index-LastPos)
            maxLen = max(thisLen,maxLen)
            CurLen = min(index-LastPos,CurLen)
            DictPos[s[index]] = index
        
        return maxLen
s1 = "abcabcbb"
s2 = "bbbbb"
s3 = "abcderh"
s4 = "tmmzuxt"
Test = Solution()
print Test.lengthOfLongestSubstring(s1)
print Test.lengthOfLongestSubstring(s2)
print Test.lengthOfLongestSubstring(s3)
print Test.lengthOfLongestSubstring(s4)
