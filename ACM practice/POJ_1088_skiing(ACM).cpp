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
	int count[20000];
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
	int Row, Column;
	cin >> Row >> Column;
//	height *t = (height *) malloc (Row * Column * sizeof(height));
	height t[20000];
	for(int i = 0; i < Row*Column; i++){
		cin >> t[i].h;
		t[i].row = i / Row;
		
		if(i % Column){
			t[i].column = t[i-1].column + 1;
		}
		else{
			t[i].column = 0;
		}
	}
	sort(t, &t[Row*Column],cmp);
	cout << LongestLength(t, Row, Column) << endl;
	return 0;
}
