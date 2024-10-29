#include <iostream>
#include<vector>
using namespace std;
class Queue{
	int * queue;
	int size=0;
	int n;
public:
	int front=0;
	int rear=-1;
	Queue(int x){
		size=0;
		n=x;
		queue=new int[x];
	}
	~Queue(){
		delete[] queue;
	}
	void enqueue(int x){
		if(size==n){
			cout << "Overflow" <<endl;
		}
		else{
			rear++;
			if(rear==n)
				rear=0;
			queue[rear]=x;
			size++;}
	}
	void dequeue(){
		if(size==0)
			cout <<"Underflow"<<endl;
		else{
			front++;
			if(front==n)
				front=0;
			size--;}
	}
	void getFront(){
		if (size==0){
			cout << "-1" <<endl;
		}
		else
			cout << queue[front] << endl;
	}
	void getRear(){
		if (size==0){
			cout << "-1" <<endl;
		}
		else
			cout << queue[rear] << endl;
	}
	void isEmpty(){
		if(size==0){
			cout << "True"<< endl;
		}
		else
			cout <<"False"<< endl;
	}
	void isFull(){
		if(size==n){
			cout << "True"<< endl;
		}else
			cout <<"False"<< endl;
	}
};
int main(){
	int n;
	cin >>n;
	string command;
	Queue que(n);
	while(cin >> command){
		if(command=="enqueue"){
			int x;
			cin>> x;
			que.enqueue(x);
		}
		if(command=="dequeue"){
			que.dequeue();
		}
		if(command=="front"){
			que.getFront();
		}
		if(command=="rear"){
			que.getRear();
		}
		if(command=="isEmpty"){
			que.isEmpty();
		}
		if(command=="isFull"){
			que.isFull();
		}
	}
	return 0;
}
