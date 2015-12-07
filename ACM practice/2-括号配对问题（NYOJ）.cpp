//括号配对问题（come from 语言入门ACM）

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<stack>

using namespace std;

void judge(char *brackets, char *temp, int i) {
	stack<char> bra;
	for (unsigned int j = 0; j < strlen(brackets); j++) {
		if (!bra.empty()) {
			if (*(brackets + j) == ')') {
				if (bra.top() == '(') {
					bra.pop();
				}
				else {
					bra.push(*(brackets + j));
				}

			}
			else if (*(brackets + j) == ']') {
				if (bra.top() == '[') {
					bra.pop();
				}
				else {
					bra.push(*(brackets + j));
				}

			}
			else {
				bra.push(*(brackets + j));
			}
		}
		else {
			bra.push(*(brackets + j));
		}
	}
	if (bra.empty())
		temp[i] = '1';
	else temp[i] = '0';
}

int main() {
	int n;
	cin >> n;
	char *temp = (char *)malloc(n * sizeof(char));
	for (int i = 0; i<n; i++) {
		char brackets[20000];
		cin >> brackets;
		judge(brackets, temp, i);
	}
	for (int i = 0; i<n; i++) {
		if (temp[i] == '1')
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
