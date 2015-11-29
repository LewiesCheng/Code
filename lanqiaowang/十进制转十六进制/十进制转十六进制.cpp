#include<iostream>

using namespace std;

int fun(int num,char *result){
	int carry = num % 16;
	switch(carry){
		case 10:*result='A';break;
		case 11:*result='B';break;
		case 12:*result='C';break;
		case 13:*result='D';break;
		case 14:*result='E';break;
		case 15:*result='F';break;
		default:*result='0'+carry; 
	}
	if(num/16>0){
		fun(num/16,result+1);
	}
}
int main(){
	char result[8];
	int i=0;
	for(i=0;i<8;i++){
		result[i]='0';
	} 
	int a;
	cin>>a;
	fun(a,result);
	for(i=7;i>=0;i--){
		if(result[i] != '0') break;
	}
	for(i;i>=0;i--){
		cout<<result[i];
	}
	return 0;
} 
