#include<iostream>
#include<vector>
using namespace std;
using Matrix = std::vector<std::vector<long long>>;


int FastExp(int base, int n)
{
    int result = 1;
    while (n)
    {
        if (n & 1)
            result *= base;
        base *= base;
        n >>= 1;
    }
    return result;
}


Matrix multiply(const Matrix& A, const Matrix& B) {
	Matrix C(2, std::vector<long long>(2));
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
			C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j];
        }
    }
    return C;
}


Matrix FastExp(Matrix base,int n)
{
	Matrix result = {{1, 0}, {0, 1}};
    while (n)
    {
        if (n & 1)
            result = multiply(result, base);
        base = multiply(base, base);
		n >>= 1;
    }
    return result;
}

long long Fibonacci(int n)
{
    if (n == 0) return 0;
    Matrix base = {{1, 1}, {1, 0}};
    Matrix result = FastExp(base, n - 1);
    return result[0][0];
}


int main(){

	int n;
	cout << "斐波那契数列的第几项：";
	cin >> n;
	cout << "结果是：" << Fibonacci(n);
    return 0;
}