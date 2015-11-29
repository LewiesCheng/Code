#include<iostream>

using namespace std;

int main(){
	int i = 0,j = 0;
	int num;
	for(i=1;i<10;i++){
		for(j=0;j<10;j++){
			num = i*1001+j*110;
			cout<<num<<"\t";
		}
	}
	return 0;
}
