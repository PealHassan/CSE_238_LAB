//time complexity is o(nlogn)
//space complexity is o(n)
#include<bits/stdc++.h>  
using namespace std;
struct Heap {
	int cur = 0;
	int arr[100011]; // max size is 100010
	void insert(int x);  
	void pop();  
	int root();  
	int size();
};

void Heap::insert(int x) {
	cur++;  
	arr[cur] = x;  
	int ncur = cur;
	while(ncur != 1) {
		int parent = ncur/2;
		if(arr[parent]>=arr[ncur]) break;  
		swap(arr[ncur],arr[parent]);  
		ncur = parent;
	}
}

void Heap::pop() {
	swap(arr[cur],arr[1]);  
	cur--;  
	int ncur = 1;  
	while(ncur<=cur) {
		int ch1 = ncur*2, ch2 = ncur*2 + 1;  
		if(ch1>cur && ch2>cur) break;
		else if(ch1 <= cur && ch2 <= cur) {
			if(arr[ch1]>arr[ch2] && arr[ch1]>arr[ncur]) {
				swap(arr[ch1],arr[ncur]);
				ncur = ch1; 
			}
			else if(arr[ch2]>arr[ch1] && arr[ch2]>arr[ncur]){
				swap(arr[ch2],arr[ncur]);
				ncur = ch2;  
			}
			else break;
		}
		else if(ch2>cur && arr[ch1]>arr[ncur]) {
			swap(arr[ch1],arr[ncur]);
			ncur = ch1;  
		}
		else if(ch1>cur && arr[ch2]>arr[ncur]) {
			swap(arr[ch2],arr[ncur]);
			ncur = ch2;  
		}
		else break;
	}
}

int Heap::root() {
	return arr[1];
}

int Heap::size() {
	return cur;
}
int main() {
	int n;  
	cin >> n ;  
	Heap heap;
	for(int i = 0; i<n; i++) {
		int x;  
		cin >> x;  
		heap.insert(x);
	}
	cout << heap.size() << endl;
	for(int i = 1; i<=n; i++) {
		cout << heap.root() << endl;
		heap.pop();  
	}
	return 0;
}