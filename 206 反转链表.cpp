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
//就地逆置法
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

//头插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		ListNode temp_head(0);
		while(head){
			ListNode *next=head->next;
			head->next=temp_head.next;
			temp_head.next=head;
			head=next;
		}
		return temp_head.next;
	}
};
//比较
1、
	ListNode temp_head(0);//临时节点
	ListNode *new_head=NULL;//指针变量



