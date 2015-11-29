#include<iostream>
#include<cstdlib>

using namespace std;

int Max(int *num,int n){
	int max = num[0];
	for(int i=1;i<n;i++){
		if(max < num[i]){
			max = num[i];
		}
	}
	return max;
}

int Min(int *num,int n){
	int min = num[0];
	for(int i=1;i<n;i++){
		if(min > num[i]){
			min = num[i];
		}
	}
	return min;
	
}

int Sum(int *num,int n){
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += num[i];
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	int *num = (int *)malloc(n*sizeof(int));
	for(int i=0;i < n;i++){
		cin>>num[i];
	}
	cout<<Max(num,n)<<endl;
	cout<<Min(num,n)<<endl;
	cout<<Sum(num,n)<<endl;
	return 0;
}


