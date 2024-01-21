// Power Of Numbers
#include<stdio.h>
#include<math.h>
long long rev(long long n){
	long long r=0;
	while(n>0){
		r=r*10+n%10;
		n/=10;
	}
	return r;
}
long long power(int N, int R)
    {
        int MOD = 1e9 + 7;
        // step 1
        if (R == 0)
            return 1;
        // step 2
        long long ans = power(N, R - 1);
        // step 3 . note we need to do mod as the result may
        // overflow
        ans = (ans % MOD * N % MOD) % MOD;
        return ans;
    }

int main()
{
	long long n;
	scanf("%lld",&n);
	long long r=0;
	r=rev(n);
	printf("%lld",power(n,r));
}