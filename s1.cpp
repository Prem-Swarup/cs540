#include<bits/stdc++.h>
using namespace std;



int main() {
	std::cout << std::fixed << std::setprecision(6);
	float i=1 ;
	float sum=0 ;
	float last=-1 ;
	while(sum!=last){
		last = sum ;
		sum += 1/i ;
		i++ ;
	}

	cout<<sum<<" "<<i<<endl ;
	return 0 ;
}
