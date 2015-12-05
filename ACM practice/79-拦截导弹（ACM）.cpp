#include<iostream>
#include<cstdlib>

using namespace std;

int LISLength ( int * height, int m ){
	int * t = (int *) malloc (m * sizeof(int));
	int max = 0;
	for(int i = 0; i < m; i++){
		t[i] = 1;
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < i; j++){
			if(height[i] < height[j] && t[i] < t[j]+1){
				t[i] = t[j] + 1;
			}
		}
		if(t[i] > max){
			max = t[i];
		}
	}
	return max;
}

int main( ){
	int N;
	cin >> N;            //     1 <= N <= 10
	int count[10];
	for(int i = 0; i < N; i++){
		int m;           //     1 <= m <= 20
		cin >> m;
		int *height = (int *) malloc (m * sizeof(int));
		for(int j = 0; j < m; j++){
			cin >> height[j];
		}
		count[i] = LISLength(height, m);
	}
	for(int i = 0; i < N; i++){
		cout << count[i] << endl;
	}
	return 0; 
}
