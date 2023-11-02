#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	double a=(1+sqrt(5))/2;
	double b=(1-sqrt(5))/2;
	int n; cin>>n;
	double a1=1;
	double a2=1;
	for(int i=1;i<=n;i++)
	{
		a1=a1*a;
		a2=a2*b;
	}
	double sum=(a1-a2)/sqrt(5);
    int sum1 =sum;
    sum1 %= 10007;
    cout << sum1;
}
