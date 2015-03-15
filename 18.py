#4Sum
class Solution:
    # @return a list of lists of length 4, [[val1,val2,val3,val4]]
    def fourSum(self, num, target):
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
                pos1 = j+1
                pos2 = iLen-1
                firstelem = 1
                while pos1<pos2:
                    if firstelem!=1 and NumList[pos1]==NumList[lastK]:
                        pos1 += 1
                        continue
                    iResult = NumList[i]+NumList[j]+NumList[pos1]+NumList[pos2]
                    lastK = pos1
                    if iResult<target:
                        pos1 += 1
                        firstelem = 0
                    elif iResult>target:
                        pos2 -= 1
                        firstelem = 1
                    else:
                        AnsList.append([NumList[i],NumList[j],NumList[pos1],NumList[pos2]])
                        pos1 += 1
                        pos2 -= 1
                        firstelem = 0
        return AnsList
