#include<iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	char *ch = new char[N*3];
	char (*p)[3] = (char(*)[3])ch;
	for(int i=0; i < N; i++){
		cin >> p[i];
	}
	char temp;
	for(int i=0; i < N; i++){
		if(p[i][0] > p[i][1]){
			temp = p[i][0];
			p[i][0] = p[i][1];
			p[i][1] = temp;
		}
		if(p[i][0] > p[i][2]){
			temp = p[i][0];
			p[i][0] = p[i][2];
			p[i][2] = temp;
		}
		if(p[i][1] > p[i][2]){
			temp = p[i][1];
			p[i][1] = p[i][2];
			p[i][2] = temp;
		}
		cout << p[i][0] << ' ' << p[i][1] << ' ' << p[i][2] << endl;
	}
	return 0;
} 
