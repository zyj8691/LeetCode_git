/**
使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
示例:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
说明:

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
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

//双栈法
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
		if(/*_output.empty()*/!_output.empty()){//当output_stack不空的时候
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