#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int N,M;
	int arr[102];
	int sum[102];
	int times[102];
	cin>>N;
	cin>>M;
	for(int i=0 ; i< N; i++ ) {
		cin>>arr[i];
		times[i] = 0;
	}
	sum[0]=arr[0];
	for(int i=1; i< N;i++) {
		sum[i]= sum[i-1] + arr[i];
	}
	for(int i=0;i<M; i++) {
		int a,b, x = 0;
		cin>>a>>b;
		x = sum[b-1];
		if(a > 1) {
			x -= sum[a-2];
		}
	//	cout<<"x "<<x<<" a "<<a<<" b "<<b<<endl;
		if(x > 0) {
			for(int j = a-1; j<b;j++) {
				times[j]++;
			}
		}
	}
	int y = 0;
	for(int i=0;i<N;i++) {
		y+= arr[i]*times[i];
	//	cout<<"i: "<<arr[i]<<" times[i] "<<times[i]<<endl;
	}
	cout<<y<<endl;
	return 0;
}