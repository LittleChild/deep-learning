#include<iostream>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        // if(pHead==NULL){
        //     return NULL;
        // }
        // RandomListNode *clonehead=new RandomListNode(pHead->label);
        // clonehead->next=pHead->next;
        // clonehead->random=pHead->random;

        // clonehead->next=Clone(pHead->next);
        // return clonehead;
        
        /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
        */
        if(pHead==NULL){
            return NULL;
        }
        RandomListNode *clonehead=pHead;
        while(pHead!=NULL){
            RandomListNode *temp=new RandomListNode(pHead->label);
            temp->next=pHead->next;
            pHead->next=temp;
            pHead=temp->next;
        }
        RandomListNode *head=clonehead;
        while(clonehead!=NULL){
            if(clonehead->random!=NULL)
                clonehead->next->random=clonehead->random->next;
            clonehead=clonehead->next->next;
        }
        RandomListNode*result=head->next;
        RandomListNode*cur;
        while(head->next!=NULL){
            cur=head->next;
            head->next=cur->next;
            head=cur;
        }
        return result;
    }
};

int main(){
    return 0;
}