/** ACM-11 from 南阳理工  **/ 
/*  奇偶数分离  */ 

#include<iostream>

using namespace std;

int main( ){
	int i;     // 2<=i<=30   i组测试数据
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
