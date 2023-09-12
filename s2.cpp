#include<bits/stdc++.h>
using namespace std;
#define float double
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC optimize("O3")
#define fastio ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
	fastio
	float i=1 ;
	float sum=0 ;
	float last=-1 ;
	while(sum!=last){
		last = sum ;
		sum += 1/i ;
		i++ ;
		if((long long)i%100000000==0) {
			cout<<i<<" "<<sum<<endl ;
		}
	}

	cout<<sum<<endl ;
	return 0 ;
}
