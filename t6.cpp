#include<bits/stdc++.h>
using namespace std;

#define type1 float
#define type2 double
#define IOS ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const long long divisor = 1e3 ;

int main() {
	IOS
	std::cout << std::fixed << std::setprecision(6);
	type1 i=1 ;
	type2 sum=0 ;
	type2 last=-1 ;

	float mx1 = 16777216.000000 ;
	float mx2 = mx1 +1 ;
	
	cout<<mx1<<" "<<++mx1<<" "<<mx1+1<<" "<<mx2<<endl ;
	return 0 ;
	while(sum!=last){
		last = sum ;
		sum += 1/i ;
		i++ ;
//		if((long long)i%divisor==0){
//			cout<<"iteration number: "<<i<<"   "<<"sum: "<<sum<<endl ;
//		}
			cout<<"iteration number: "<<i<<"   "<<"sum: "<<sum<<endl ;
	}

	cout<<sum<<" "<<i<<endl ;
	return 0 ;
}
