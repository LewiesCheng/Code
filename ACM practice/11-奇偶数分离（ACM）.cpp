/** ACM-11 from ������  **/ 
/*  ��ż������  */ 

#include<iostream>

using namespace std;

int main( ){
	int i;     // 2<=i<=30   i���������
	cin >> i;
	int n[30] = {0};
	for(int j=0; j < i; j++){
		cin >> n[j];
	}
	for(int j=0; j < i; j++){
		int k = 1;
		while(k <= n[j]){
			cout << k << ' ';
			k += 2;
		}
		cout << endl;
		k = 2;
		while(k <= n[j]){
			cout << k << ' ';
			k += 2;
		}
		cout << endl << endl;
	}
	return 0;
} 
