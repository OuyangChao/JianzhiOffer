/*
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
n<=39
*/

/*
˼·���Ե�����
*/

class Solution {
public:
    int Fibonacci(int n) {
		if (n == 0 || n == 1)
			return n;
		vector<int> ivec(n + 1, 0);
		ivec[0] = 0;
		ivec[1] = 1;
		for (size_t i = 2; i < n + 1; ++i)
		{
			ivec[i] = ivec[i - 1] + ivec[i - 2];
		}
		return ivec[n];
    }
};