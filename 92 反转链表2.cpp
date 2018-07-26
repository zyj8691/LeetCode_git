/*
反转从位置 m 到 n 的链表。用一次遍历在原地完成反转。

例如：
给定 1->2->3->4->5->NULL, m = 2 和 n = 4,

返回 1->4->3->2->5->NULL.

注意:
给定 m，n 满足以下条件：

1 ≤ m ≤ n ≤ 列表长度。
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len=n-m+1;//计算需要逆置的结点个数
		ListNode *pre_head=NULL;//初始化开始逆置的节点的前驱
		ListNode *result=head;//最终转换后的链表头，非特殊情况即为head
		while(head&&--m){
			pre_head=head;//记录head的前驱
			head=head->next;
		}
		ListNode *modify_list_tail=head;//将modify_list_tail指向当前的head，即逆置后的链表尾
		ListNode *new_head=NULL;
		while(head&&change_len){//逆置change_len个结点
			ListNode *next=head->next;
			head->next=new_head;
			new_head=head;
			head=next;
			change_len--;//每完成一个结点逆置，change_len--
		}
		
		modify_list_tail->next=head;//连接逆置后的链表尾与逆置段的后一个结点
		if(pre_head){
			pre_head->next=new_head;//如果pre_head不空，说明不是从第一个节点开始逆置的m>1
									//将逆置链表开始的结点前驱与逆置后的头结点连接
		}
		else{
			result=new_head;//如果pre_head为空，说明m==1从第一个节点开始逆置结果即为逆置后的头结点
		}
		return result;
};