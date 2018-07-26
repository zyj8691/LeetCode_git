/**
���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

push(x) -- ��Ԫ�� x ����ջ�С�
pop() -- ɾ��ջ����Ԫ�ء�
top() -- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�
ʾ��:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.
*/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 
 /**solution*/
 #include<stack>
class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		_data.push(x);
		if (/*x <= _min.top()*/_min.empty()){
			_min.push(x);
		}
		else{
			if (x>_min.top()){
				x = _min.top();
			}
			_min.push(x);
		}
	}

	void pop() {
		_data.pop();//����ջ����Сֵջͬʱ����
		_min.pop();
	}

	int top() {
		return _data.top();
	}

	int getMin() {
		return _min.top();
	}
private:
	std::stack<int>_data;//����ջ
	std::stack<int>_min;//��Сֵջ
};


