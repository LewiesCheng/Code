#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int n,i = 0,a;
	cin>>n;
	int *array = (int *)malloc(n*sizeof(int));
	for(i = 0;i<n;i++){
		cin>>array[i];
	}
	cin>>a;
	for(i = 0;i < n;i++){
		if(array[i] == a)
			break;
	}
	if(i < n){
		cout<<i+1;
	}
	else
		cout<<-1;
	return 0;
} 
