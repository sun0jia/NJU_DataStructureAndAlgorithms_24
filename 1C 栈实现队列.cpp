#include <iostream>
#include <stack>
using namespace std;
stack<int> A,B;
void enqueue(){
	A.push(0);
	cout << "push A"<< endl;
}
void dequeue(){
	if(B.empty()){
		while(!A.empty()){
			B.push(A.top());
			A.pop();
			cout << "move A B" << endl;
		}
		B.pop();
		cout << "pop B"<< endl;
	}
	else{
		B.pop();
		cout << "pop B"<< endl;
	}

}
int main(){
	string command;
	while(cin>> command){
		if(command=="enqueue"){
			enqueue();
		}
		if(command=="dequeue"){
			dequeue();
		}
	}
	return 0;
}
