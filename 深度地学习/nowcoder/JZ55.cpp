#include<iostream>
#include<map>
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        map<int,int>c;
        while (pHead!=NULL)
        {
            c[pHead->val]++;
            if(c[pHead->val]>=2){
                return pHead;
                break;
            }
            pHead=pHead->next;
        }
        return NULL;
    }
};