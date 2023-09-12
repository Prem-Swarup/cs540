#include<bits/stdc++.h>
using namespace std;

#define type1 float
#define type2 double

const long long divisor = 1e7 ;

template <typename T>
void check_epsilon(T one) {
	cout<<scientific ;
	T epsilon = 1 ;
	while(one + epsilon > one) {
		epsilon /= 2 ;
	}
	cout<<"machine epsilon: "<<epsilon<<endl ;
}

int main() {
	std::cout << std::fixed << std::setprecision(6);
	type1 i=1 ;
	type2 sum=0 ;
	type2 last=-1 ;

	int epsilon_1 = 1, one = 1;
	while(one + epsilon_1/2 > one) {
		epsilon_1 /= 2 ;
	}


	type2 epsilon_2 = 1, one_ = 1;
	while(one_ + epsilon_2 > one_) {
		epsilon_2 /= 2 ;
	}
	check_epsilon(one) ;
	cout<<"epsilon_1: "<<epsilon_1<<"\nepsilon_2: "<<epsilon_2<<endl ; 

	return 0 ;

	int a=2 ;
	float b=2 ;
	b += 1/a ;
	cout<<b<<" "<<1/a<<endl ;return 0;
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
