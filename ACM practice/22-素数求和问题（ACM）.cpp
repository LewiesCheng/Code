/** �����������  **/
/* from  ��������ACM - 22 */  

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

//  �ж� num �Ƿ�Ϊ���� 
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
	int M;                  //0< M < 10  M��������� 
	cin >> M;
	int sum[10] = {0};      //���ÿ��������ݵ������� 
	int N[10];              //ÿ��������ݵĸ��� N
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
