/*
ʹ�ö���ʵ��ջ�����в�����

push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��
ע��:

��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek/pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�
����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
    }
    
    /** Get the top element. */
    int top() {
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
 #include <queue>
class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		std::queue<int>temp_queue;
		temp_queue.push(x);
		while (!_data.empty()){
			temp_queue.push(_data.front());
			_data.pop();
		}
		while (!temp_queue.empty()){
			_data.push(temp_queue.front());
			temp_queue.pop();
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int x = _data.front();
		_data.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		return _data.front();
	}


	/** Returns whether the stack is empty. */
	bool empty() {
		return _data.empty();
	}
private:
	std::queue<int>_data;
};

 