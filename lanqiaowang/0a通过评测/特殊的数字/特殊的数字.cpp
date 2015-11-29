#include<iostream>
using namespace std;

int main(){
	int num = 100;
	int i,j,k;
	for(num=100;num<1000;num++){
		i = num % 10;
		j = num / 10 % 10;
		k = num / 100;
		if(num == i*i*i+j*j*j+k*k*k)
			cout<<num<<endl;
	}
	return 0;	
}
