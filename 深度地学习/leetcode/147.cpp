#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* result=new ListNode(-1);
        ListNode* cur=head;
        ListNode* tail=cur;
        if(head==NULL)
            return head;
        while (head)
        {
            cur=result;
            while (cur->next && cur->next->val<head->val)
            {
                cur=cur->next;
            }
            tail=head;
            head=head->next;
            tail->next=cur->next;
            cur->next=tail;
        }
        return result->next;
    }
};

int main(){
    return 0;
}