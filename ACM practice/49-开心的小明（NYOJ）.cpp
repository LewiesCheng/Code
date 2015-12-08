/**  开心的小明  **/
/*  from NYOJ-49  */
//  背包问题

#include<iostream>
#include<cstdlib>
using namespace std;

int main( ){
	int N, sum[101] = { 0 };
	cin >> N;
	int v[25] = { 0 };
	int w[25] = { 0 };
	for(int i=0; i < N; i++){
		int money, m;
		cin >> money >> m;
		for(int j=1; j <= m; j++){
			cin >> v[j] >> w[j];
		}
		int *f = (int *) malloc ( (money+1) * sizeof(int) );
		for(int j=0; j <= money; j++){
			f[j] = 0;
		}
		for(int j=1; j <= m; j++){
			for(int k=money; k > 0; k--){
				if(v[j] <= k){
					f[k] = f[k] > f[k-v[j]]+v[j]*w[j] ? f[k]:f[k-v[j]]+v[j]*w[j];
				}
			}
		}
		sum[i] = f[money];
		free(f);
	}
	for(int i=0; i < N; i++){
		cout << sum[i] << endl;
	}	
	return 0;
} 
