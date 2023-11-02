#include<cstdio>
#include<cstring>
#define ll long long
const ll mod=10007;
struct num
{
	ll s5,z;//sqrt(5)项,整项
};

long long mo(ll x)
{
	return ((x%mod)+mod)%mod;
}

num mul(num x,num y)
{
	num ans;
	ans.z=mo(mo(x.z*y.z)+mo(5ll*x.s5)*y.s5);
	ans.s5=mo(mo(x.s5*y.z)+mo(x.z*y.s5));
	return ans;
}
num qpow(num x,ll y)
{
	num ans;
	ans.s5=0;ans.z=1;
	while (y){
		if (y&1) ans=mul(x,ans);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	n--;
	num a,b,c,d,e,f;
	a.s5=700000005;
	c.z=a.z=b.z=b.s5=d.z=500000004;
	d.s5=mo(-500000004);
	c.s5=mo(-700000005);
	e=mul(a,qpow(b,n));
	f=mul(c,qpow(d,n));
	printf("%lld\n",mo(e.z+f.z));
	return 0;
}