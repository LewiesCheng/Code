#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n,i=1;
	cin>>n;
	int total = n*(n-1)/2;
	int *array = (int *)malloc(total*sizeof(int));
	array[0]=1;
	cout<<array[0]<<endl;
	if(n>1){
		array[1] = 1;
		array[2] = 1;
		cout<<array[1]<<' '<<array[2]<<endl;
	}	
	for(i=2;i<=n;i++){
		array[i*(i-1)/2] = 1;
		array[i*(i+1)/2-1] = 1;
	}
	for(i=3;i<=n;i++){
		cout<<1;
		for(int j=i*(i-1)/2+1;j<i*(i+1)/2-1;j++){
			array[j] = array[j-i] + array[j-i+1];
			cout<<' '<<array[j];
		}
		cout<<' '<<1<<endl;
	}
	return 0;
} 
