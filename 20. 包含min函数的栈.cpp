/*
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
*/

/*
˼·��
����ջstackData������ջstackMin
push: �ѵ�ǰstackData�е���Сֵpush��stackMin��
min: stackMin��ջ������ջ����Сֵ
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