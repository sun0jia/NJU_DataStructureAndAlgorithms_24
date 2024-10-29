#include <iostream>
using namespace std;
class MyArray{
public:
	int* ar;
	int size=0;
	int capacity=10;
	MyArray() {
		ar = new int[capacity]; // 初始化动态数组
	}

	~MyArray() {
		delete[] ar; // 析构函数释放内存
	}
	void resize(int new_capacity) {
		int* new_array = new int[new_capacity];
		for (int i = 0; i < size; ++i) {
			new_array[i] = ar[i];
		}
		delete[] ar;
		ar = new_array;
		capacity = new_capacity;
	}
	void append(int x){
		if(size>=capacity){
			resize(2*capacity);
		}
		ar[size++]=x;

	}
	void set(int x,int y){
		ar[x]=y;
	}
	void erase(int x){
		for(int i=x;i<size-1;i++){
			ar[i]=ar[i+1];
		}
		size--;
		if(size<capacity/2){
			resize(capacity/2);
		}
	}
	int get(int x){
		return ar[x];
	}
};
int main(){
	string command;
	MyArray ar;
	while(cin >>command){
		if(command=="append"){
			int x;
			cin >> x;
			ar.append(x);
		}
		if(command=="set"){
			int x,y;
			cin >> x >> y;
			ar.set(x,y);
		}
		if(command=="erase"){
			int x;
			cin >>x;
			ar.erase(x);
		}
		if(command=="get"){
			int x;
			cin >>x;
			cout << ar.get(x) <<endl;
		}
		if(command=="size"){
			cout << ar.size << endl;
		}
		if (command=="capacity"){
			cout <<ar.capacity << endl;
		}
		if(command=="print"){
			for(int i=0;i<ar.size;i++){
				cout << ar.get(i) <<' ';
			}
			cout << endl;
		}
	}return 0;
}
