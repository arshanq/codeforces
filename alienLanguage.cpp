#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
void travelUtils(int arr[][26], stack<int> st, vector<int> visited, int node) {
	for(int i= 0; i< 26;i++) {
		if(arr[node][i] && !visited[i]) {
			travelUtils(arr, st, visited, i);
		}
	}
	visited[node] = 1;
	st.push(node);
} 
 
 
void printStack(stack<int> st) {
	while(!st.empty())  {
		cout<<st.top() + 'a';
		st.pop();
	}
}
 
void findTopologicalSorting(int arr[][26]) {
	stack<int> orderStack;
	vector<int> visited;
	for(int i = 0; i<26;i++) {
		for(int j = 0; j< 26;j++) {
			if(arr[i][j]) {
				travelUtils(arr, orderStack, visited, i);
			}
		}
	}
	printStack(orderStack);
}

 bool isCycle(int arr[][26]) {
 	int set[26];
 	for(int i = 0 ;i<26; i++) set[i] = -1;
 	for(int i = 0; i< 26; i++) {
 		for(int j = 0; j<26; j++) {
 			if(arr[i][j]) {
 				if(set[i] && set[j]) {
 					return true;
 				}
 				set[i] = 1;
 				set[j] = 1;
 			}
 		}
 	}
 	return false;
 }
 
int main() {
	bool isPossible = true;
	int N;
	vector<string> input;
	cin>>N; 
	int arr[26][26] = {0};
	int i = 0 ;
	while(N--) {
		cin>>input[i++];
	}
	for(int i =1 ; i<N; i++) {
		int lCur = input[i].length(), lPre = input[i-1].length();
		int min =  lCur> lPre ? lPre : lCur;
		for(int j = 0; j < min; j++) {
			if(input[i][j] != input[i-1][j]) {
				int parent =(int) input[i-1][j] - 'a';
				int child = (int) input[i][j] - 'a';
				if(arr[child][parent]) {
					isPossible = false;
					break;
				}
				arr[parent][child] = 1;
				break;
			} 
		}
		if(input[i-1][min-1] == input[i][min-1] && 
			lPre > min) {
				isPossible = false;
			}
	}
	if(isPossible && !isCycle(arr)) {
		findTopologicalSorting(arr);
	}
	else {
		cout<<"IMPOSSIBLE";
	}
	return 0;
}