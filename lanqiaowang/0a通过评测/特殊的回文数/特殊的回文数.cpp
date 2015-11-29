#include<iostream>

using namespace std;

int main(){
	int n;
	cin>>n;  // 1 <= n <= 54
	if(n % 2){
		if(n<=45){
			for(int i=1;i<10;i++){
				for(int j=0;j<10;j++){
					for(int k=1;k<10;k+=2){
						if(2*i+2*j+k == n){
							cout<<i*10001+j*1010+k*100<<endl;
						}
					}
				}
			}
		}
	}
	else{
		if(n<=45){
			for(int i=1;i<10;i++){
				for(int j=0;j<10;j++){
					for(int k=0;k<10;k+=2){
						if(2*i+2*j+k == n){
							cout<<i*10001+j*1010+k*100<<endl;
						}
					}
				}
			}
		}
		for(int i=1;i<10;i++){
			for(int j=0;j<10;j++){
				for(int k=0;k<10;k++){
					if(i+j+k == n/2){
						cout<<i*100001+j*10010+k*1100<<endl;
					}
				}
			}
		}
	}
}
