//time complexity o(n)
// space complexity o(n)
#include<bits/stdc++.h>
using namespace std;  
struct Heap {
	int cur = 0;
	void heapify(int arr[], int n);
	void utility(int arr[], int n, int x);
	void pop(int arr[]);
	int root(int arr[]);  
	int  size();  
};

void Heap::utility(int arr[], int n, int x) {
	int ncur = x;  
	while(ncur <= cur) {
		int ch1 = ncur*2, ch2 = ncur*2 + 1;  
		if(ch1>cur && ch2>cur) break;
		else if(ch1 <= cur && ch2 <= cur) {
			if(arr[ch1]>=arr[ch2] && arr[ch1]>arr[ncur]) {
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
void Heap::heapify(int arr[],int n) {
	cur = n;  
	for(int i = cur; i>=1; i--) {
		int ch1 = i*2, ch2 = i*2 + 1;  
		if(ch1 > cur && ch2 > cur) continue;  
		else if(ch1 <= cur && ch2 <= cur) {
			if(arr[ch1] > arr[ch2] && arr[ch1] > arr[i]) {
				swap(arr[ch1],arr[i]);  
				utility(arr,n,ch1);  
			}
			else if(arr[ch2] > arr[ch1] && arr[ch2] > arr[i]) {
				swap(arr[ch2],arr[i]);
				utility(arr,n,ch2);    
			}
			else continue;  
		}
		else if(ch1 <= cur && arr[ch1] > arr[i]) {
			swap(arr[ch1],arr[i]); 
			utility(arr,n,ch1);
		}
		else if(ch2 <= cur && arr[ch2] > arr[i]) {
			swap(arr[ch2],arr[i]);
			utility(arr,n,ch2); 
		}
	}
}

void Heap::pop(int arr[]) {
	swap(arr[cur],arr[1]);  
	cur--;  
	utility(arr,cur,1);  
}

int Heap::root(int arr[]) {
	return arr[1];
}

int Heap::size() {
	return cur;
}

int main() {
	int n;  
	cin >> n;
	int arr[n+1];
	for(int i = 1; i<=n; i++) cin >> arr[i];  
	Heap heap;  
	heap.heapify(arr,n);
	for(int i = 1; i<=n; i++) {
		cout << heap.root(arr) << endl;  
		heap.pop(arr);
	}  
	return 0;
}