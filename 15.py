#3Sum 
# sorted and fix two to find the other one
class Solution:
    # @return a list of lists of length 3, [[val1,val2,val3]]
    def threeSum(self, num):
        NumList = sorted(num)
        iLen = len(NumList)
        AnsList = []
        lastI = 0
        lastJ = 0
        lastK = 0
        for i in range(0,iLen):
            if i!=0 and NumList[i]==NumList[lastI]:
                continue
            lastI = i
            lastJ = 0
            for j in range(i+1,iLen):
                if j!=i+1 and NumList[j]==NumList[lastJ]:
                    continue
                lastJ = j
                lastK = 0
                for k in range(j+1,iLen):
                    if k!=j+1 and NumList[k]==NumList[lastK]:
                        continue
                    lastK = k
                    if NumList[i]+NumList[j]+NumList[k]==0:
                        AnsList.append([NumList[i],NumList[j],NumList[k]])
                        break
                    elif NumList[i]+NumList[j]+NumList[k]>0:
                        break
        return AnsList
Test = Solution()
print Test.threeSum([3,0,-2,-1,1,2])
