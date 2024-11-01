#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Heap {
private:
	int size;
	vector<int> heap; // 当前堆的大小
public:
	Heap(int x) : size(0) {
		if(x==1)//小顶堆
		heap.push_back(0);// 堆从索引1开始
		if(x==-1)//大顶堆
			heap.push_back(1000000000);
	}

	void push1(int x) {//小顶堆
		size++;
		heap.push_back(x); // 将新元素添加到堆的末尾
		int idx = size;
		while (idx >= 1 && heap[floor(idx / 2)] > heap[idx]) {
			swap(heap[floor(idx / 2)], heap[idx]);
			idx = floor(idx / 2);
		}
	}
	void push2(int x) {//大顶堆
		size++;
		heap.push_back(x); // 将新元素添加到堆的末尾
		int idx = size;
		while (idx >= 1 && heap[floor(idx / 2)] < heap[idx]) {
			swap(heap[floor(idx / 2)], heap[idx]);
			idx = floor(idx / 2);
		}
	}
	int popMin() {//小顶堆
		int min_item = heap[1]; // 获取堆顶元素
		heap[1] = heap[size];
		heap.pop_back(); // 移除最后一个元素
		size--;
		MinHeapify(1); // 重新调整堆
		return min_item;
	}
	int popMax(){//大顶堆
		int min_item = heap[1]; // 获取堆顶元素
		heap[1] = heap[size];
		heap.pop_back(); // 移除最后一个元素
		size--;
		MaxHeapify(1); // 重新调整堆
		return min_item;
	}
	void MinHeapify(int idx) {
		int idx_l = 2 * idx;
		int idx_r = 2 * idx + 1;
		int idx_min = idx;

		if (idx_l <= size && heap[idx_l] < heap[idx_min]) {
			idx_min = idx_l;
		}
		if (idx_r <= size && heap[idx_r] < heap[idx_min]) {
			idx_min = idx_r;
		}
		if (idx_min != idx) {
			swap(heap[idx_min], heap[idx]);
			MinHeapify(idx_min); // 递归调整
		}
	}
	void MaxHeapify(int idx) {
		int idx_l = 2 * idx;
		int idx_r = 2 * idx + 1;
		int idx_min = idx;

		if (idx_l <= size && heap[idx_l] > heap[idx_min]) {
			idx_min = idx_l;
		}
		if (idx_r <= size && heap[idx_r] > heap[idx_min]) {
			idx_min = idx_r;
		}
		if (idx_min != idx) {

			swap(heap[idx_min], heap[idx]);
			MaxHeapify(idx_min); // 递归调整
		}
	}
	int top() {
		return heap[1];
	}
};
int main()
{
	int num;
	int k=0;
	Heap heapmin(-1);
	Heap heapmax(1);
	while(std::cin >>num){
		k++;
		if(k%2==1){
			if(num<heapmin.top()){
				heapmin.push2(num);
				heapmax.push1(heapmin.popMax());
			}
			else{
				heapmax.push1(num);
			}
			std:: cout<< heapmax.top()<<endl;
		}
		else{
			if(num>heapmax.top()){
				heapmax.push1(num);
				heapmin.push2(heapmax.popMin());
			}
			else
				heapmin.push2(num);
			std::cout<<heapmin.top()<<endl;
		}
	}
	return 0;
}
/**
 * 理解堆的结构
 * 小顶堆的vector并不是从小到大
 * 大顶堆也不是从大到小
 * 所以说直接pop最后一个是不可以得到最大/小得元素的！
 * 还是要实现一个大一个小顶堆
 * plus 注意边界 10^9你怎么看成5的宝宝*/
