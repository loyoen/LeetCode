#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>>
#include <stack> 
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *pNode = head, *pAns = NULL, *pTmp = NULL;
        stack<ListNode *> sNodes, sNodesTmp;
        while(pNode!=NULL)
        {
            sNodes.push(pNode);
            pNode = pNode->next;
            if(sNodes.size()==k)
            {
                while(!sNodes.empty())
                {
                    if(pAns==NULL)
                    {
                        pAns = sNodes.top();
                        pTmp = pAns;
                        pTmp->next = NULL;
                    }
                    else
                    {
                        pTmp->next = sNodes.top();
                        pTmp = pTmp->next;
                        pTmp->next = NULL;
                    }
                    sNodes.pop();
                }
            }
        }
        while(!sNodes.empty())
        {
            sNodesTmp.push(sNodes.top());
            sNodes.pop();
        }
        while(!sNodesTmp.empty())
        {
            if(pAns==NULL)
            {
                pAns = sNodesTmp.top();
                pTmp = pAns;
                pTmp->next = NULL;
            }
            else
            {
                pTmp->next = sNodesTmp.top();
                pTmp = pTmp->next;
                pTmp->next = NULL;
            }
            sNodesTmp.pop();
        }
        return pAns;
    }
};
int main()
{
    Solution Test;
    ListNode p1(1),p2(2),p3(3);
    p1.next = &p2;
    p2.next= &p3;
    ListNode *p = Test.reverseKGroup(&p1,2);
    while(p!=NULL)
    {
		cout<<p->val;
		p= p->next;
	}
	system("pause");
    return 0;
}
