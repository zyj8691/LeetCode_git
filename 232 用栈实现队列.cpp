/**
ʹ��ջʵ�ֶ��е����в�����

push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�
ʾ��:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false
˵��:

��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek/pop from top, size, �� is empty �����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
    }
    
    /** Get the front element. */
    int peek() {
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
 
 
 /**solution*/
#include<stack>
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		std::stack<int> temp_stack;
		while (!_data.empty()){
			temp_stack.push(_data.top());
			_data.pop();
		}
		temp_stack.push(x);
		while (!temp_stack.empty()){
			_data.push(temp_stack.top());
			temp_stack.pop();
		}
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		int x = _data.top();
		_data.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		return _data.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return _data.empty();
	}
private:
	std::stack<int>_data;
};

//˫ջ��
#include<stack>
class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		_input.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		adjust();
		int x=_output.top();
		_output.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		adjust();
		return _output.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (_input.empty()&&_output.empty());
	}
private:
	void adjust(){
		if(/*_output.empty()*/!_output.empty()){//��output_stack���յ�ʱ��
			return;
		}
		while(!_input.empty()){
			_output.push(_input.top());
			_input.pop();
		}
	}
	std::stack<int>_input;
	std::stack<int>_output;
};