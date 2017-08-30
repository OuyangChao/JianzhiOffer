/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

/*
思路：
以pushV = {1 2 3 4 5 6}, popV = {4 6 5 3 2 1}为例：
在pushV中找到popV中的第一个元素（即4），同时将该元素之前的元素push到stkV中，此时stkV中有{1 2 3}；
从popV中的第二个元素开始，判断stkV的栈顶是否等于popV的元素：
如果相等，则将其pop出来；否则判断是不是pushV中新的元素，是的话push到stkV中。

popV中第二个元素6不等于stkV的栈顶3，而且6不等于pushV中的下一个元素5，因此push到stkV中，此时stkV中有{1 2 3 5}；
继续判断，popV中第三个元素5等于stkV的栈顶5，弹出，此时stkV中有{1 2 3}；
以此类推，如果最终stkV为空，则表示popV是pushV的弹出顺序，否则不是。
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> stkV;
		size_t i = 0, j = 0;
		for (; i < pushV.size() && j < popV.size(); ++i)
		{
			if (pushV[i] != popV[j])
				stkV.push(pushV[i]);
			else
				break;
		}
		for (size_t k = j + 1; k < popV.size(); ++k)
		{
			if (!stkV.empty() && stkV.top() == popV[k])
				stkV.pop();
			else if (i + 1 < pushV.size())
			{
				if (pushV[i + 1] != popV[k])
					stkV.push(pushV[i + 1]);
				++i;
			}
		}
		if (stkV.empty())
			return true;
		else
			return false;
    }
};