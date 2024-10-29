#include <iostream>
#include <vector>
using namespace std;
vector<int> ll;
void pushFront(int x){
	ll.insert(ll.begin(), x);
}
void pushBack(int x){
	ll.push_back(x);
}
void search(int x){
	int judge=0;
	for(int i=0;i<ll.size();i++){
		if(ll[i]==x){
			judge=1;
			break;}
	}
	cout << judge<< endl;
}
void remove(int x){
	int i=0;
	for(;i<ll.size();i++){
		if(ll[i]==x){
			break;
		}
	}
	if(i<ll.size())
		ll.erase(ll.begin()+i);
}
int main(){
	string command;
	while (cin >> command){
		if(command=="pushFront"){
			int x;
			cin >> x;
			pushFront(x);
		}
		if(command=="pushBack"){
			int x;
			cin >> x;
			pushBack(x);
		}
		if(command=="search"){
			int x;
			cin >> x;
			search(x);
		}
		if(command=="remove"){
			int x;
			cin >> x;
			remove(x);
		}
		if(command=="print"){
			for(int i=0;i<ll.size();i++){
				cout << ll[i] << ' ';
			}
			cout <<endl;
		}
	}return 0;
}
/**
 * void pushFront(int x){
    if (ll.size()==0){
        ll.push_back(x);
        return;
    }
	for(int i=1;i<=ll.size();i++){
		ll[i]=ll[i-1];
	}
	ll[0]=x;
}
 这段代码错在 比如12345 pushfront 8 会变成811111
 而且i会越界 vector是不可以这样写的
 */
