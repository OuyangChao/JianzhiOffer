/*
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,
如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....
LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 
现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。
*/

/*
思路：先排序，再统计0的个数，再统计相邻数字之间的空缺总数。
*/

class Solution {
public:
    bool IsContinuous(vector<int> number) {
		if (number.size() < 1)
			return false;
		int hashTable[14] = {0};
		for (size_t i = 0; i < number.size(); ++i)
			++hashTable[number[i]];
		int index = 0;
		for (int i = 0; i < 14; ++i)
		{
			for (int j = 0; j < hashTable[i]; ++j)
				number[index++] = i;
		}
		int numberOfZero = hashTable[0];
		int numberofGap = 0;
		int small = numberOfZero;
		int big = small + 1;
		while (big < number.size())
		{
			if (number[small] == number[big])
				return false;
			numberofGap += number[big] - number[small] - 1;
			small = big;
			++big;
		}
		return numberofGap > numberOfZero ? false : true;
    }
};