#include <iostream>
#include <vector>
using namespace std;
long long  MergeSort(vector<int> &nums){
	int n=nums.size();
	if(n==0||n==1)
		return 0;
	vector<int> left;
	vector<int> right;
	for(int i=0;i<n;i++){
		if(i<n/2){
			left.push_back(nums[i]);
		}
		else{
			right.push_back(nums[i]);
		}
	}long long count=0;
	count+=MergeSort(left);
	count+=MergeSort(right);
	int idx1=0;
	int idx2=0;
	int i=0;
	for(;i<n&&idx1<left.size()&&idx2<right.size();i++){
		if(left[idx1]<right[idx2]){
			nums[i]=left[idx1];
			idx1++;
			count+=idx2;
		}
		else{
			nums[i]=right[idx2];
			idx2++;
		}
	}
	while(idx1<left.size()){
		nums[i]=left[idx1];
		idx1++;
		count+=idx2;
		i++;
	}
	while(idx2<right.size()){
		nums[i]=right[idx2];
		idx2++;
		i++;
	}
	return count;
}
int main()
{
	int n;
	vector<int> nums;
	cin >> n;
	int num;
	while(cin >> num){
		nums.push_back(num);
	}
	cout << MergeSort(nums);
}
