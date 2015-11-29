#include<iostream>

using namespace std;

int main(){
	char sum[20];
	int i = 0,n;
	for(i;i < 20;i++){
		sum[i] = '0';
	}
	cin>>n;
	int carry = 0;
	for(int j = 1;j <= n;j++){
		i = 0; 
		carry = sum[i] - '0' + j;
		sum[i] = carry % 10 + '0';
		carry = carry / 10;
		while(carry != 0){
			i++;
			carry = sum[i] - '0' + carry;
			sum[i] = carry % 10 + '0';
			carry = carry / 10;
		}
	}
	for(i = 19;i >= 0;i--){
		if(sum[i] != '0') break;
	}
	for(i;i >= 0;i--){
		cout<<sum[i]-'0'; 
	}
	return 0;
}
