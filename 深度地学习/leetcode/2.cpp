#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head;
        ListNode *p=&head;
        int bit=0;
        while(l1 || l2){
            int s=bit;
            if(l1)
                s+=l1->val;
            if(l2)
                s+=l2->val;
            if(s>9){
                s-=10;
                bit=1;
            }
            else{
                bit=0;
            }
            ListNode *t=new ListNode(s);
            p->next=t;
            p=p->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(bit){
            ListNode *t=new ListNode(bit);
            p->next=t;
        }
        p=&head;
        return p->next;
    }
};

int main(){
    Solution s;
    return 0;
}