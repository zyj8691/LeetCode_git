/**
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2

*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
 
 /*solution*/
 //二叉树可解  堆可解
 
 //堆解法
 #include <iostream>
#include<queue>
#include <vector>
//#include <algorithm>
#include <functional>//必须添加
//using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		if (big_queue.empty()){
			big_queue.push(num);
			return;
		}
		if (big_queue.size() == small_queue.size()){
			if (num<big_queue.top()){
				big_queue.push(num);
			}
			else{
				small_queue.push(num);
			}
		}
		else if (big_queue.size() > small_queue.size()){
			if (num > big_queue.top()){
				small_queue.push(num);
			}
			else{
				small_queue.push(big_queue.top());
				big_queue.pop();
				big_queue.push(num);
			}
		}
		else if (big_queue.size() < small_queue.size()){
			if (num < big_queue.top()){
				big_queue.push(num);
			}
			else{
				big_queue.push(big_queue.top());
				small_queue.pop();
				small_queue.push(num);
			}
		}
	}

	double findMedian() {
		if (big_queue.size() == small_queue.size()){
			return(big_queue.top() + small_queue.size()) / 2;
		}
		else if(big_queue.size()>small_queue.size()){
			return big_queue.top();
		}
		return small_queue.top();
	}
private:
	std::priority_queue<int, std::vector<int>, std::greater<int>>small_queue;
	std::priority_queue<int, std::vector<int>, std::less<int>>big_queue;
};
 
 
 
 