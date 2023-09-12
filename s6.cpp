#include<bits/stdc++.h>
using namespace std;



int main() {
	std::cout << std::fixed << std::setprecision(6);
	int i=1 ;
	float sum=0 ;
	float last=-1 ;
	int tmp = 2 ;
	cout<<(1/tmp)<<endl ;
	while(sum!=last){
		last = sum ;
		sum += 1/i ;
		i++ ;
	}

	cout<<sum<<" "<<i<<endl ;
	return 0 ;
}
