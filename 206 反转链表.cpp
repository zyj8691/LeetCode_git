/*
反转一个单链表。

进阶:
链表可以迭代或递归地反转。你能否两个都实现一遍？
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head=NULL;//指向新链表头结点的指针
		while(head){
		ListNode *next=head->next;//备份head->next
		head->next=new_head;//更新head->next
		new_head=head;//移动new_head
		head=next;//遍历链表
    }
	return new_head;//返回新链表头结点
};