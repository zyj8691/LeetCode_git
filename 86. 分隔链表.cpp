/**
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
你应当保留两个分区中每个节点的初始相对位置。
示例:
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

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
	ListNode* partition(ListNode* head, int x) {
		ListNode less_head(0);
		ListNode more_head(0);
		ListNode *less_ptr = &less_head;
		ListNode *more_ptr = &more_head;
		while (head)
		{
			if (head->val < x){
				less_ptr->next = head;
				less_ptr = head;
			}
			else{
				more_ptr->next = head;
				more_ptr = head;
			}
			head = head->next;
		}
		less_ptr->next = more_head.next;
		more_ptr->next = NULL;
		return less_head.next;
	}
};