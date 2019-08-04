// The only property required to solve the complete problem is GCD(U, V) = GCD(U \% V, V)GCD(U,V)=GCD(U%V,V).
// Now the problem remains finding the value of (A^N + B^N) % (A-B)

// things to learn form this problem
// 1. calculate exponentiation in log time
// 2. exponentiation calculation via modulo, which is called modulo exponentiation
// 3. GCD(x,y) is GCD(x%y,y) and GCD(0,x) is x
// 4. use __int128 which is integer of 128 bits, to prevent overflow

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long calculateExponent(long long a, long long b,long long mod=MOD)
    {
        long long res = 1;
        while(b)
        {
            if(b & 1)
                res = ((__int128)res * a) % mod;
            a = ((__int128)a * a) % mod;
            b >>= 1;
        }
        return res;
    }
     
long long go(long long a,long long b,long long n)
{
	if(a==b)//then gcd(0,x) is x
		return (calculateExponent(a,n)+calculateExponent(b,n))%MOD;
	else// return gcd(((a^n)%a-b)+(b^n)%(a-b)),a-b), this is mathematically correct and it would control the overflow
		{
			long long x=(calculateExponent(a,n,a-b)+calculateExponent(b,n,a-b))%(a-b);
			return __gcd(x,a-b);//using inbuilt __gcd fun
		}
}
int main(){
	int t;
	long long a,b,n;
	cin>>t;
	while(t--){
		cin>>a>>b>>n;
		cout<<go(a,b,n)<<endl;
		// calculateExponent(a,b);
	}
}