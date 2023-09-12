#include<bits/stdc++.h>
using namespace std;

#define type1 double
#define type2 double

const long long divisor = 1e10 ;

int main() {
	std::cout << std::fixed << std::setprecision(6);
	type1 i=1 ;
	type2 sum=0 ;
	type2 last=-1 ;

	while(sum!=last){
		last = sum ;
		sum += 1/i ;
		i++ ;
		if((long long)i%divisor==0){
			cout<<"iteration number: "<<i<<"   "<<"sum: "<<sum<<endl ;
		}
	}

	cout<<sum<<" "<<i<<endl ;
	return 0 ;
}
