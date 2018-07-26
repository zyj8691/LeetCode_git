/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
    }
};
*/
#include <iostream>
#include <map>
#include <vector>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

//void init(ListNode* head){
//	ListNode *a = (ListNode*)malloc(sizeof(ListNode));
//	ListNode *b = (ListNode*)malloc(sizeof(ListNode));
//	ListNode *c = (ListNode*)malloc(sizeof(ListNode));
//	ListNode *d = (ListNode*)malloc(sizeof(ListNode));
//	ListNode *e = (ListNode*)malloc(sizeof(ListNode));
//	ListNode *f = (ListNode*)malloc(sizeof(ListNode));
//
//	a->val = 1;
//	b->val = 2;
//	c->val = 3;
//	d->val = 4;
//	e->val = 5;
//	f->val = 6;
//
//	a->next = b;
//	b->next = c;
//	c->next = d;
//	d->next = e;
//	e->next = f;
//	f->next = NULL;
//	head = a;
//
//}
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* L1, ListNode* L2){
		ListNode temp_head(0);
		ListNode *pre = &temp_head;
		while (L1&&L2){
			if (L1->val < L2->val){
				//pre->next->val = L1->val;
				pre->next = L1;
				L1 = L1->next;
			}
			else{
				//pre->next->val = L2->val;
				pre->next = L2;
				L2 = L2->next;
			}
			pre = pre->next;
		}
		if (L1){
			pre->next = L1;
		}
		if (L2){
			pre->next = L2;
		}
		return temp_head.next;
	}
};


int main()
{
	ListNode a(1);
	ListNode b(4);
	ListNode c(6);
	ListNode d(0);
	ListNode e(5);
	ListNode f(7);

	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	

	Solution solve;
	ListNode*head = solve.mergeTwoLists(&a,&d);
	while (head){
		printf("label = %d  ", head->val);
		head = head->next;
	}
	
	return 0;
}
