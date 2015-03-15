//3Sum Closest
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int iLen = num.size();
        QuickSort(num,0,iLen-1);
        int iMin = -1;
        int ans = 0;
        for(int i=0;i<iLen;i++)
        {
            int FirstElem = num[i];
            //cout<<FirstElem<<endl;
            int j = i + 1, k = iLen-1;
            while(j<k)
            {
                int total = FirstElem + num[j] + num[k];
                if(total==target)
                    return total;
                else if(total>target)
                {
                    iMin = iMin==-1?total-target:iMin;
                    iMin = iMin>total-target?total-target:iMin;
                    k--;
                }
                else if(total<target)
                {
                    iMin = iMin==-1?target-total:iMin;
                    iMin = iMin>target-total?target-total:iMin;
                    j++;
                }
                if(iMin==abs(total-target))
                    ans = total;
            }
        }
        return ans;
    }
    void QuickSort(vector<int> &num,int start,int end)
    {
        int i = start, j = end;
        int key = num[i];
        if(start<end)
        {
            while(i<j)
            {
                while(i<j && num[j]>key)
                    j--;
                num[i] = num[j];
                while(i<j && num[i]<=key)
                    i++;
                num[j] = num[i];
            }
            num[i] = key;
            QuickSort(num,start,i-1);
            QuickSort(num,i+1,end);
        }
    }
};
