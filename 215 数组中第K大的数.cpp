/**
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
    }
};

*/
#include <iostream>
#include<queue>
#include <vector>
//#include <algorithm>
#include <functional>//必须添加
//using namespace std;

class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		std::priority_queue<int, std::vector<int>, std::greater<int>>Q;
		for (int i = 0; i < nums.size(); i++){
			if (/*nums[i]<Q.top()*/Q.size()<k){
				Q.push(nums[i]);
			}
			else if (nums[i]>Q.top()){
				Q.pop();
				Q.push(nums[i]);
			}
		}
		return Q.top();
	}
};


