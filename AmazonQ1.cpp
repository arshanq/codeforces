#include <iostream>
using namespace std;
void printArr(int Arr[], int s) {
	for(int i=0;i<s;i++) {
		cout<<Arr[i]<<" ";
	}
	cout<<endl;
}
void generateAllCombinations(int A[], int B[], int C[],int a,int b,int len,int m, int n, bool printFlag) {
	if(printFlag) {
		for(int i = n; i< b; i++) {
			if(B[i] > C[len-1]) {
				C[len++] = B[i];
				printArr(C, len);
				generateAllCombinations(A,B,C,a,b,len,m,n+1,!printFlag);
				len--;
			}
		}
	} else {
		for(int i = m; i<a;i++) {
			if(len == 0 ||
			A[i] > C[len - 1]) {
				C[len++] = A[i];
				generateAllCombinations(A,B,C,a,b,len ,m+1,n,!printFlag);
				len--;
			}
		}
	}
}

int main() {
	// your code goes here
	
	int A[] = {10,15,20,25};
	int B[] = {1, 2,3, 15, 24, 35};
	int a = sizeof(A)/ sizeof(A[0]);
	int b = sizeof(B)/ sizeof(B[0]);
	int C[a+b];
	generateAllCombinations(A, B,C, a, b,0,0,0, false);
	return 0;
}