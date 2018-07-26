/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    }
};
*/
//方案1 K个链表按照顺序合并K-1次

//方案2 将k*n个结点放到vector中，再将vector排序，再将结点顺序相连
bool cmp(const ListNode*a, const ListNode*b){
	return a->val < b->val;
}

class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>&lists){
		std::vector<ListNode*>node_vec;
		for (int i = 0; i < lists.size(); i++){
			ListNode* head = lists[i];//遍历k个链表，将结点全部添加至node_vec
			while (head){
				//node_vec.push_back(new ListNode(lists[i]->val));
				node_vec.push_back(head);
				head = head->next;
			}
		}
		if (node_vec.size() == 0)
			return NULL;
		std::sort(node_vec.begin(), node_vec.end(), cmp);
		for (int i = 1; i < node_vec.size(); i++){
			node_vec[i - 1]->next = node_vec[i];
		}
		node_vec[node_vec.size - 1]->next = NULL;
		return node_vec[0];
	
	}
};
//方案3 对k个链表进行分治，两两进行合并

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

bool cmp(const ListNode*a, const ListNode*b){
	return a->val < b->val;
}

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

	ListNode* mergeKLists(std::vector<ListNode*>&lists){
		if (lists.size() == 0){
			return NULL;
		}
		if (lists.size() == 1){
			return lists[0];
		}
		if (lists.size() == 2){
			return mergeTwoLists(lists[0], lists[1]);
		}
		int mid = lists.size() / 2;
		std::vector<ListNode*>sub1_lists;
		std::vector<ListNode*>sub2_lists;
		for (int i = 0; i < mid; i++){
			sub1_lists.push_back(lists[i]);
		}
		for (int i = mid; i < lists.size(); i++){
			sub2_lists.push_back(lists[i]);
		}
		ListNode* L1 = mergeKLists(sub1_lists);
		ListNode* L2 = mergeKLists(sub2_lists);

		return mergeTwoLists(L1, L2);
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
	ListNode g(2);
	ListNode h(3);

	a.next = &b;
	b.next = &c;
	d.next = &e;
	e.next = &f;
	g.next = &h;


	Solution solve;
	std::vector<ListNode*>lists;
	lists.push_back(&a);
	lists.push_back(&d);
	lists.push_back(&g);
	ListNode*head = solve.mergeKLists(lists);
	while (head){
		printf("label = %d\n", head->val);
		head = head->next;
	}
	
	return 0;
}


