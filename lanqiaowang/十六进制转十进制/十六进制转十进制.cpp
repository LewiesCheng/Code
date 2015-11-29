#include<iostream>
#include<cmath>
using namespace std;

int main(){
	char str[9];
	cin>>str;
	int result = 0;
	int i=0; 
	for(i=0;i<9;i++){
		if(str[i]=='\0') break;
	}
	int temp = i - 1;
	for(int j=0;j<=i;j++){
		if(str[j]>='A'){
			result = result + (str[j]-'A'+10)*(int)pow(16,temp);
		}
		else{
			result = result + (str[j]-'0')*(int)pow(16,temp);
		}
		temp--;
	}
	cout<<result;
	return 0;
} 
