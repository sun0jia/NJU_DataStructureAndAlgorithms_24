#include <iostream>
#include <stack>
using namespace std;
int main(){
	stack<int> track;
	int cur;
	int num=1;
	while(cin >> cur){
		if(cur==num){
			num++;
		}
		else{
			if(!track.empty() && track.top()==cur){
				track.pop();
				continue;
			}
			if(!track.empty() && cur<track.top())
				break;
			else{
				for(;num!=cur;num++){
					track.push(num);
				}
				num++;
			}
		}
	}
	if(track.empty())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
