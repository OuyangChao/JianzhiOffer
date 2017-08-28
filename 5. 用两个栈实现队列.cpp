/*
������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
*/

/*
˼·��stack1����push��
pop��ʱ�����stack2Ϊ�գ����Ƚ�stack1�е�Ԫ��pop��stack2�У��ٽ�stack2��ջ��pop������
���stack2�ǿգ�ֱ�ӽ�stack2��ջ��pop������
*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
			
		}
		int top = stack2.top();
		stack2.pop();
		return top;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};