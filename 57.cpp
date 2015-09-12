#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<int> timePoint;
        vector<int> timeFlag;
        for(int i=0;i<intervals.size();i++)
        {
            timePoint.push_back(intervals[i].start);
            timePoint.push_back(intervals[i].end);
            timeFlag.push_back(1);
            timeFlag.push_back(0);
        }
        vector<int>::iterator iter = timePoint.begin();
        vector<int>::iterator iterFlag = timeFlag.begin();
        for(;iter!=timePoint.end();iter++)
        {
            if(*iter>=newInterval.start)
                break;
            iterFlag++;
        }
        timePoint.insert(iter, newInterval.start);
        timeFlag.insert(iterFlag, 1);
        iter = timePoint.begin();
		iterFlag = timeFlag.begin();
        for(;iter!=timePoint.end();iter++)
        {
            if(*iter>newInterval.end)
                break;
            iterFlag++;
        }
        timePoint.insert(iter, newInterval.end);
        timeFlag.insert(iterFlag, 0);
        
        vector<Interval> ans;
        int cntStart = 0;
        int curstart = 0, curend = 0;
        for(int i=0;i<timePoint.size();i++)
        {
            if(cntStart==0)
                curstart = timePoint[i];
                
            if(timeFlag[i]==1)
                cntStart ++;
            else
                cntStart --;
                
            if(cntStart==0)
            {
                curend = timePoint[i];
                ans.push_back(Interval(curstart,curend));
            }
        }
        return ans;        
    }
};
int main()
{
	Solution s;
	Interval s1(1,2);
	Interval s2(3,5);
	Interval s3(6,7);
	Interval s4(8,10);
	Interval s5(12,16);
	vector<Interval> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	Interval s10(4,9);
	vector<Interval> ans = s.insert(v,s10);
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i].start << " " << ans[i].end <<endl;
	}
	system("pause");
	return 0;
} 
