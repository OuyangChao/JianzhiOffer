/*
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ�
��������1,2,3,4,5��ĳջ��ѹ��˳��
����4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵģ�
*/

/*
˼·��
��pushV = {1 2 3 4 5 6}, popV = {4 6 5 3 2 1}Ϊ����
��pushV���ҵ�popV�еĵ�һ��Ԫ�أ���4����ͬʱ����Ԫ��֮ǰ��Ԫ��push��stkV�У���ʱstkV����{1 2 3}��
��popV�еĵڶ���Ԫ�ؿ�ʼ���ж�stkV��ջ���Ƿ����popV��Ԫ�أ�
�����ȣ�����pop�����������ж��ǲ���pushV���µ�Ԫ�أ��ǵĻ�push��stkV�С�

popV�еڶ���Ԫ��6������stkV��ջ��3������6������pushV�е���һ��Ԫ��5�����push��stkV�У���ʱstkV����{1 2 3 5}��
�����жϣ�popV�е�����Ԫ��5����stkV��ջ��5����������ʱstkV����{1 2 3}��
�Դ����ƣ��������stkVΪ�գ����ʾpopV��pushV�ĵ���˳�򣬷����ǡ�
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