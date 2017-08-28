/*
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

/*
思路：依然是斐波那契数列
*/

class Solution {
public:
    int rectCover(int number) {
		if (number == 0 || number == 1 || number == 2)
			return number;
		vector<int> ivec(number, 0);
		ivec[0] = 1;
		ivec[1] = 2;
		for (size_t i = 2; i < number; ++i)
		{
			ivec[i] = ivec[i - 1] + ivec[i - 2];
		}
		return ivec[number - 1];
    }
};