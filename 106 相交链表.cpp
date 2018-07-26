/*
编写一个程序，找到两个单链表相交的起始节点。
例如，下面的两个链表：
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。
注意：
如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//方法一
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		std::set<ListNode*> node_set;//设置查找集合node_set
		while(headA){
			 node_set.insert(headA);//将链表A中的结点插入node_set
			 headA=headA->next;//遍历链表A
		}
		while(headB){
			if(node_set.find(headB)!=node_set.end()){
				return headB;//当在headB中找到第一个出现在node_set中的结点时
			}
			headB=headB->next;//遍历链表B
		}
		return NULL;
    }
};
//方法二
int get_list_length(ListNode *head){
	int len=0;
	while(head){
		len++;
		head=head->next;
	}
	return len;
}

ListNode *forward_long_list(int long_len,int short_len,ListNode *head){
	int delta=long_len-short_len;
	while(head&&delta){
		head=head->next;
		delta--;
	}
	return head;
}

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int list_A_len=get_list_length(headA);
		int list_B_len=get_list_length(headB);
		if(list_A_len>list_B_len){
			headA=forward_long_list(list_A_len,list_B_len,headA);
			//如果链表A长，移动headA到对应位置
		}
		else{
			headB=forward_long_list(list_B_len,list_A_len,headB);
			//如果链表B长，移动headA到对应位置
		}
		while(headA&&headB){
			if(headA==headB)
				return headA；
			headA=headA->next;
			headB=headB->next;
		}
		return NULL;
	}
};

