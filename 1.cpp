//快排 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,q[N];
void quick_sort(int l,int r)
{ 
	if(l==r)
		return;
	int x =q[l];
	int i=l-1,j=r+1;
	while(i<j){
		do i++; while (q[i]<x);
		do j--; while(q[j]>x);
		if(i<j)	swap(q[i],q[j]); 
	}
	quick_sort(l,j);
	quick_sort(j+1,r);
}
void quick_sort2(int l,int r)
{ 
	if(l==r)
		return;
	int x =q[l];
	int i=l-1,j=r+1;
	while(i<j){
		do i++; while (q[i]>x);
		do j--; while(q[j]<x);
		if(i<j)	swap(q[i],q[j]); 
	}
	quick_sort2(l,j);
	quick_sort2(j+1,r);
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> q[i];
	}	
	quick_sort2(0,n-1);
	for(int i=0;i<n;i++){
		cout << q[i] << " ";
	} 
} 
