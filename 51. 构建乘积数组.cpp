/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。
*/

/*
思路：
C[i]=A[0]*A[1]*...*A[i-1]
D[i]=A[i+1]*...*A[n-1]
C[i]=C[i-1]*A[i-1]
D[i]=D[i+1]*A[i+1]
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
		vector<int> B(A.size());
		B[0] = 1;
		for (int i = 1; i < A.size(); ++i)
		{
			B[i] = B[i - 1] * A[i - 1];
		}
		int temp = 1;
		for (int i = A.size() - 2; i >= 0; --i)
		{
			temp *= A[i + 1];
			B[i] *= temp;
		}
		return B;
    }
};