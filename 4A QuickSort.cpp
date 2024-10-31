#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void medium(vector<int>&nums,int left,int right){
	int mid=left+(right-left)/2;
	if (nums[left] > nums[mid]) swap(nums[left], nums[mid]);
	if (nums[left] > nums[right]) swap(nums[left], nums[right]);
	if (nums[mid] > nums[right]) swap(nums[mid], nums[right]);
}
void QuickSort(vector<int> &nums,int left,int right){
	if(left>=right){
		return;
	}
	if(left+1==right){
		if(nums[left]>nums[right])
			swap(nums[left],nums[right]);
		return;
	}
	if(left+2==right){
	    medium(nums,left,right);
	    return;
	}
	medium(nums,left,right);
	int i;
	int j=left;//next position
	int pivot=nums[right];
	for(i=left;i<right;i++){
		if(nums[i]<pivot){
			swap(nums[i],nums[j]);
			j++;
		}
	}
	swap(nums[right],nums[j]);
	QuickSort(nums,left,j-1);
	QuickSort(nums,j+1,right);
}
int main() {
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	QuickSort(nums,0,nums.size()-1);
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << nums[i];
	}
	cout << endl;
	return 0;
}

