#include<iostream>
#include<cstring>

using namespace std;

//计算LCS的长度 
int LCSLength (string str1, string str2){
	int m = str1.size();
	int n = str2.size();
	
//	int **c = new int* [m+1];         //c[m][n]保存str1，str2的LCS的长度 
//	for(int i = 0; i <= m; i++){
//		c[i] = new int [n+1]; 
//	}
	
	int c[1000][1000]; 	
	for(int i = 0; i <= m; i++){
		c[i][0] = 0;
	}
	for(int j = 1; j <= n; j++){
		c[0][j] = 0;
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(str1[i-1] == str2[j-1]){
				c[i][j] = c[i-1][j-1] + 1;
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j] = c[i-1][j];
			}
			else{
				c[i][j] = c[i][j-1];
			}
		}
	}
	return c[m][n];
}

int main(){
	int N;
	cin >> N;
	int len[100];
	
	for(int i = 0; i < N; i++){
		string str1, str2;
		cin >> str1 >> str2;
		len[i] = LCSLength(str1, str2);
	}
	
	for(int i = 0; i < N; i++){
		cout << len[i] << endl;
	}
	return 0;
}
