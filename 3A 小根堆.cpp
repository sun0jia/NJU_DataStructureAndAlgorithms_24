#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

class Heap {
private:
	int size; // 当前堆的大小
	int num;  // 插入次数
	vector<int> heap; // 存储堆的数组
	map<int, int> mp;  // key: push次数, value: 值
	map<int, int> mp1; // key: 值，value: 索引

public:
	Heap() : size(0), num(0) {
		heap.push_back(0); // 堆从索引1开始，索引0保留为0
	}

	void push(int x) {
		size++;
		num++;
		heap.push_back(x); // 将新元素添加到堆的末尾
		int idx = size;
		mp[num] = x; // 记录当前插入的次数和对应的值
		mp1[x] = idx; // 记录新插入的值及其索引

		// 向上调整堆
		while (idx >= 1 && heap[floor(idx / 2)] > heap[idx]) {
			swap(mp1[heap[floor(idx / 2)]], mp1[heap[idx]]);
			swap(heap[floor(idx / 2)], heap[idx]);
			idx = floor(idx / 2);
		}

	}

	int pop() {
		int min_item = heap[1]; // 获取堆顶元素
		mp1.erase(min_item); // 从索引映射中移除
		heap[1] = heap[size]; // 将最后一个元素放到堆顶
		mp1[heap[1]]=1;
		heap.pop_back(); // 移除最后一个元素
		size--;
		MinHeapify(1); // 重新调整堆
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
			swap(mp1[heap[idx_min]], mp1[heap[idx]]);
			swap(heap[idx_min], heap[idx]);
			MinHeapify(idx_min); // 递归调整
		}
	}

	int top() {
		if (size == 0) {
			throw runtime_error("Heap is empty.");
		}
		return heap[1];
	}

	int getsize() {
		return size;
	}

	void decrease(int i, int k) {
		if (mp.find(i) == mp.end()) {
			throw runtime_error("Invalid operation: index does not exist.");
		}
		int k0 = mp[i]; // 原值
		int idx = mp1[k0]; // 找到原值的索引
		heap[idx] = k; // 更新为新值
		mp1.erase(k0); // 删除旧值的映射
		mp1[k] = idx; // 添加新值的映射
		mp[i] = k; // 更新插入的次数

		// 向上调整堆
		while (idx >= 1 && heap[floor(idx / 2)] > heap[idx]) {
			swap(mp1[heap[floor(idx / 2)]], mp1[heap[idx]]);
			swap(heap[floor(idx / 2)], heap[idx]);
			idx = floor(idx / 2);
		}
	}
};

int main() {
	Heap heap;
	string command;

	while (cin >> command) {
		if (command == "push") {
			int x;
			cin >> x;
			heap.push(x);
		} else if (command == "pop") {
			heap.pop();
		} else if (command == "top") {
			cout << heap.top() << endl;
		} else if (command == "size") {
			cout << heap.getsize() << endl;
		} else if (command == "decrease") {
			int i, k;
			cin >> i >> k;
			heap.decrease(i, k);
		}
	}

	return 0;
}
/**
 * push(x)：将元素 x插入堆中。
pop()：删除并返回堆中的最小元素。
top()：返回堆中的最小元素，但不删除它。
size()：返回堆中元素的数量。
decrease(i, k)：将第i次 push 操作（其他类型操作不参与编号）插入的元素减少为k，保证k小于原值。*/
