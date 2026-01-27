class MyQueue {
	stack<int> in, out;
public:
	MyQueue() {}
	void push(int x) {
		in.push(x);
	}
	int pop() {
		in2out();
		int x = out.top();
		out.pop();
		return x;
	}
	int peek() {
		in2out();
		return out.top();
	}
	void in2out() {
		if (out.empty()) {
			while (!in.empty()) {
				int x = in.top();
				in.pop();
				out.push(x);
			}
		}
	}
	bool empty() {
		return in.empty() && out.empty();
	}
};