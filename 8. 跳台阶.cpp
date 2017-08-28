/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

/*
思路1：斐波那契数列
思路2：排列组合，列举所有需要的步数
*/

class Solution {
public:
    int jumpFloor(int number) {
		if (number == 1 || number == 2)
			return number;
		vector<int> ivec(number, 0);
		ivec[0] = 1;
		ivec[1] = 2;
		for (size_t i = 2; i < number; ++i)
		{
			ivec[i] = ivec[i - 1] + ivec[i - 2];
		}
		return ivec[number - 1];
		
		/*
		int sum = 0;
		int minz = number % 2 == 0 ? number / 2 : (number / 2 + 1);
		for (int z = minz; z <= number; ++z)
		{
			unsigned long long A = 1;
			unsigned long long B = 1;
			for (int i = 1; i <= min(number - z, 2 * z - number); ++i)
			{
				A *= i;
				B *= (z - i + 1);
			}
			sum += B / A;
		}	
		return sum;
		*/
    }
};