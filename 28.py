#Median of Two Sorted Arrays
'''
    This problem is to find the K-th element in two sorted arrays.
    if A[K/2-1]<B[K/2-1]:
        K-th element is between A[k/2-1:] and B[:k/2-1]
'''
class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def judge(self,S,L):
        Dict = {}
        iLen = 0
        for item in L:
            try:
                Dict[item] += 1
            except:
                Dict[item] = 1
            iLen = len(item)
        i = 0
        while i<len(S):
            try:
                Dict[S[i:i+iLen]] -= 1
                if Dict[S[i:i+iLen]]<0:
                    return False
                i += iLen
            except:
                return False
        return True
        
    def findSubstring(self, S, L):
        totalLen = len(L)*len(L[0])
        ans = []
        for i in range(0,len(S)-totalLen+1):
            if self.judge(S[i:i+totalLen],L):
                ans.append(i)
        return ans
        
        

Test = Solution()
print Test.findSubstring("barfoothefoobarman", ["foo","bar"])
