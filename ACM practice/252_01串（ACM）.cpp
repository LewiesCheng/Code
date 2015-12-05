//ACMÃ‚∫≈252£¨01¥Æ

#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int n;
	cin >> n;
	int *m= (int *) malloc (n * sizeof(int));
	for(int i = 0; i < n; i++){
		cin >> m[i];
	}
	int t[41] = {0,0};
	t[2] = 3;
	t[3] = 5; 
	for(int i = 4; i < 41; i++){
		t[i] = t[i-1] + t[i-2];
	}
	for(int i = 0; i < n; i++){
		cout << t[m[i]] << endl;
	}
	return 0;
} 
