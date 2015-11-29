#include<iostream>

using namespace std;

int main(){
	char s[5] = {'0','0','0','0','0'};
	int i = 0,j = 0;
	for(int t=1;t<=32;t++){
		for(j=4;j>=0;j--){
			cout<<s[j]-'0';
		}
		cout<<endl;
		i = 0;
		s[i] += 1;
		j = 0;
		while(s[j] == '2'){
			s[j] = '0';
			s[j+1] += 1;
			j++;
		}		
	}
}
