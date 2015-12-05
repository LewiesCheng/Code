#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

typedef struct{
	int h;
	int row, column;
}height;

int LongestLength( height *t, int Row, int Column){
//	int *count = new int [Row * Column];
	int count[10000];
	int maxLength = 1;
	for(int i = 0; i < Row * Column; i++){
		count[i] = 1;
	}
	for(int i = 1; i < Row * Column; i++){
		for(int j = 0; j < i; j++){
			if(t[j].h < t[i].h && t[j].column == t[i].column && count[i] < count[j]+1){
				if(t[j].row == t[i].row-1 || t[j].row == t[i].row+1){
					count[i] = count[j]+1;
				}
			}
			if(t[j].h < t[i].h && t[j].row == t[i].row && count[i] < count[j]+1){
				if(t[j].column == t[i].column-1 || t[j].column == t[i].column+1){
					count[i] = count[j]+1;
				}
			}
		}
		if(maxLength < count[i]){
			maxLength = count[i];
		}
	}
	return maxLength;
}

bool cmp  (height a, height b) {
	return (a.h < b.h);
}

int main( ){
	int N;
	cin >> N;
	int * length = (int *) malloc (N * sizeof(int));
	for(int i = 0; i < N; i++){
		int Row, Column;
		cin >> Row >> Column;
//		height *t = (height *) malloc (Row * Column * sizeof(height));
		height t[10000];
		for(int j = 0; j < Row*Column; j++){
			cin >> t[j].h;
			t[j].row = j / Row;	
			if(j % Column){
				t[j].column = t[j-1].column + 1;
			}
			else{
				t[j].column = 0;
			}
		}
		sort(t, &t[Row*Column],cmp);
		
		
		length[i] = LongestLength(t, Row, Column);
	}
	
	
	for(int i = 0; i < N; i++){
		cout << length[i] << endl;
	}
	return 0;
}
