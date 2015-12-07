/** 素数求和问题  **/
/* from  语言入门ACM - 22 */  

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

//  判断 num 是否为素数 
bool isPrime (int num){     
	if(num == 1)
		return 0;
	else if(num == 2)
		return 1;
	int a = 2;
	while(a <= sqrt(num)){
		if(num%a == 0)
			return 0;
		a++;
	}
	return 1;
}

int main( ){
	int M;                  //0< M < 10  M组测试数据 
	cin >> M;
	int sum[10] = {0};      //存放每组测试数据的素数和 
	int N[10];              //每组测试数据的个数 N
	for(int i=0; i < M; i++){
		cin >> N[i];
		int *array = (int *)malloc(N[i] * sizeof(int));
		for(int j=0; j < N[i]; j++){
			cin >> array[j];
			if(isPrime(array[j]))
				sum[i] += array[j];
		}
		free(array);
	}
	for(int i=0; i < M; i++){
		cout << sum[i] << endl;
	}
	return 0;
} 
