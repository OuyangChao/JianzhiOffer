/*
����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
����ʹ�ó�����
*/

/*
˼·��
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