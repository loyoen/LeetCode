#Median of Two Sorted Arrays
'''
    This problem is to find the K-th element in two sorted arrays.
    if A[K/2-1]<B[K/2-1]:
        K-th element is between A[k/2-1:] and B[:k/2-1]
'''
class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        TotalLen = len(A) + len(B)
        if TotalLen & 1:
            k = (TotalLen-1)/2 + 1
            return float(self.findKSortedArrays(A,B,k))
        else:
            if TotalLen==0: return 0
            k1 = TotalLen/2
            k2 = TotalLen/2+1
            ans1 = self.findKSortedArrays(A,B,k1)
            ans2 = self.findKSortedArrays(A,B,k2)
            return float(ans1 + ans2) / 2
    def findKSortedArrays(self, A, B, k):
        if len(A)==0: return B[k-1]
        if len(B)==0: return A[k-1]
        if k==1: return min(A[0],B[0])
        SplitPos = (k+1)/2 - 1
        SplitPos1 = SplitPos
        SplitPos2 = SplitPos
        if k&1: SplitPos1 -= 1
        if SplitPos1+1>len(A):
            SplitPos2 = SplitPos1 - (len(A) - 1) + SplitPos2
            SplitPos1 = len(A) - 1
        elif SplitPos+1>len(B):
            SplitPos1 = SplitPos2 - (len(B) - 1) + SplitPos1
            SplitPos2 = len(B) - 1
        if A[SplitPos1]>B[SplitPos2]:
            return self.findKSortedArrays(A[:SplitPos1+1],B[SplitPos2+1:],k-SplitPos2-1)
        elif A[SplitPos1]<B[SplitPos2]:
            return self.findKSortedArrays(A[SplitPos1+1:],B[:SplitPos2+1],k-SplitPos1-1)
        else:
            return A[SplitPos1]
        
        
A = [7,7,7,7]
B = [1,4,7,9,10,12,13]
Test = Solution()
print Test.findMedianSortedArrays(A,B)
