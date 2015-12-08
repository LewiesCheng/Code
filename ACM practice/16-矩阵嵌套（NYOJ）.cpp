/**  ¾ØÕóÇ¶Ì×  **/
/*   from  NYOJ-16  */ 

#include<iostream>
#include<cstdlib>
using namespace std;

//Ñ°ÕÒ¸Ã¾ØÕóµÄÇ¶Ì×¾ØÕó
int findMax(int *a, int *b, int *count, bool *temp, int n, int sigh){
	int max = count[sigh];
	for(int i=0; i < n; i++){
		if((a[sigh] > a[i] && b[sigh] > b[i]) || (a[sigh] > b[i] && b[sigh] > a[i])){
			if(temp[i])
				max = max > count[i] + 1 ? max : count[i] + 1;
			else if(!temp[i]){
				count[i] = findMax(a, b, count, temp, n, i);
				temp[i] = 1;
				max = max > count[i] + 1 ? max : count[i] + 1;
			}
		}
	}
	temp[sigh] = 1;
	return max;
}

int main( ){
	int N;       // N (0<N<10) ²âÊÔÊý¾Ý×éÊý 
	cin >> N;
	int maxNumber[11] = {0}; 
	for(int i=0; i < N; i++){
		int n;
		cin >> n;
		int *a = (int *) malloc (n * sizeof(int));
		int *b = (int *) malloc (n * sizeof(int));
		int *count = (int *) malloc (n * sizeof(int));
		bool *temp = (bool *) malloc (n * sizeof(bool));
		for(int j=0; j < n; j++){
			cin >> a[j] >> b[j];
			count[j] = 1;
			temp[j] = 0;
		}
		for(int j=0; j < n; j++){
			if(temp[j])	continue;
			else{
				count[j] = findMax(a,b,count,temp,n,j);
				maxNumber[i] = maxNumber[i] > count[j] ? maxNumber[i] : count[j];
			}
		}
	}
	for(int i=0; i < N; i++){
		cout << maxNumber[i] << endl;
	}
	return 0;
} 
