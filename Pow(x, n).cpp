//实现 pow(x, n) ，即计算 x 的 n 次幂函数。
class Solution {
public:
    double myPow(double x, int n) {
	//快速幂
	long long N = n;
	double temp = x;
	double result = 1.0;
	if(n<0)
	{
		temp = 1/x;
		N=-N;
	}
	for(long long i = n;i>0;i/=2)
	{
	if(i%2==1)
		result = result * temp;
	temp*=temp;
	}
	return result;
	}