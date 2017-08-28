/*
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

/*
思路：stack1用于push；
pop的时候，如果stack2为空，则先将stack1中的元素pop到stack2中，再将stack2的栈顶pop出来。
如果stack2非空，直接将stack2的栈顶pop出来。
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