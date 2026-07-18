#include<iostream>
using namespace std;


int Fastexp(int base,int n)
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

int main(){

	int base, n;
	cout << "输入底数和指数：";
	cin >> base >> n;
	cout << "结果是：" << Fastexp(base, n);
    return 0;
}