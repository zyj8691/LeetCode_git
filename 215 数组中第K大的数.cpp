/**
��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�

ʾ�� 1:

����: [3,2,1,5,6,4] �� k = 2
���: 5
ʾ�� 2:

����: [3,2,3,1,2,4,5,5,6] �� k = 4
���: 4
˵��:

����Լ��� k ������Ч�ģ��� 1 �� k �� ����ĳ��ȡ�

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
#include <functional>//�������
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


