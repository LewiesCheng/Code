/**   The Triangle **/
/*   from NYOJ£®”Ô—‘»Î√≈£©  */

#include<iostream>
#include<cstdlib>
using namespace std;

int main( ){
	int N;
	cin >> N;        //   1 < N <= 100
	int *array = (int *)malloc(N * sizeof(int));
	int *sum = (int *)malloc(N * sizeof(int));
	sum[0] = 0;
	for(int i=0; i < N; i++){
		for(int j=0; j <= i; j++){
			cin >> array[j];
		}
		for(int j=i; j >= 0; j--){
			if(j == 0){
				sum[0] += array[0];
			}
			else if(j == i){
				sum[j] = sum[j-1] + array[j]; 
			}
			else{
				if(sum[j] > sum[j-1])
					sum[j] = sum[j] + array[j];
				else
					sum[j] = sum[j-1] + array[j];
			}
		} 
	}
	int max = sum[0];
	for(int i=1; i < N; i++){
		if(sum[i] > max)
			max = sum[i];
	}
	cout << max << endl;
	return 0;
} 
