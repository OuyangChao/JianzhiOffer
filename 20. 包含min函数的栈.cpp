/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

/*
思路：
数据栈stackData，辅助栈stackMin
push: 把当前stackData中的最小值push到stackMin中
min: stackMin的栈顶就是栈中最小值
*/

class Solution {
public:
    void push(int value) {
		if (stackMin.empty() || stackMin.top() > value)
			stackMin.push(value);
		else
			stackMin.push(stackMin.top());
        stackData.push(value);
    }
    void pop() {
		if (stackData.empty() || stackMin.empty())
			return;
        stackData.pop();
		stackMin.pop();
    }
    int top() {
        return stackData.top();
    }
    int min() {
        return stackMin.top();
    }
	stack<int> stackData;
	stack<int> stackMin;
};