#Longest Palindromic Substring
'''
    way1:   use KMP between the original string and its rollovered.
    way2:   dynamic programming. PalinOrNot[i][j] represent the substring from i to j is palindromic or not.
'''
# way2 use python is Time Limit Exceeded, but c++ is accept. I do not know WHY.
class Solution:
    # @return a string
    def longestPalindrome(self, s):
        sLen = len(s)
        PalinOrNot = [[0 for col in range(0,sLen)] for row in range(0,sLen)]
        Cnt = 0
        ansIndexStart = 0
        ansIndexEnd = 0
        for j in range(0,len(s)):
            for i in range(0,j+1):
                if j==i:
                    PalinOrNot[i][j] = 1
                elif j-i==1 and s[i] == s[j]:
                    PalinOrNot[i][j] = 1
                elif PalinOrNot[i+1][j-1]==1 and s[i] == s[j]:
                    PalinOrNot[i][j] = 1
                else:
                    PalinOrNot[i][j] = 0
                if PalinOrNot[i][j] == 1 and j-i+1>Cnt:
                    Cnt = j-i+1
                    ansIndexStart = i
                    ansIndexEnd = j+1
        return s[ansIndexStart:ansIndexEnd]
Test = Solution()
print Test.longestPalindrome("abac")

