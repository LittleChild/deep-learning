#include<iostream>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* re=pHead2;
        while (pHead1)
        {
            pHead2=re;
            while (pHead2)
            {
               if(pHead2==pHead1)
                    return pHead2;
                pHead2=pHead2->next;
            }
            pHead1=pHead1->next;
        }
        return NULL;
    }
};