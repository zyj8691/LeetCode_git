/**
��λ���������б��м����������б�����ż������λ�������м���������ƽ��ֵ��

���磬

[2,3,4] ����λ���� 3

[2,3] ����λ���� (2 + 3) / 2 = 2.5

���һ��֧���������ֲ��������ݽṹ��

void addNum(int num) - �������������һ�����������ݽṹ�С�
double findMedian() - ����Ŀǰ����Ԫ�ص���λ����
ʾ����

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
 //�������ɽ�  �ѿɽ�
 
 //�ѽⷨ
 #include <iostream>
#include<queue>
#include <vector>
//#include <algorithm>
#include <functional>//�������
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
 
 
 
 