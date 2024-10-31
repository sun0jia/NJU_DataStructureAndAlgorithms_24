#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	unsigned long long low = 0;
	unsigned long long high =ULLONG_MAX;
	for(int i=0;i<75;i++){
		unsigned long long mid=low+(high-low)/2;
		//为了防止low+high溢出所以要这样写
		cout << mid << endl;
		string respond;
		cin >> respond;
		if(respond=="TooBig"){
			high=mid-1;
		}
		if(respond=="TooSmall"){
			low=mid+1;
		}
		if(respond=="Correct"){
			return 0;
		}
		cout << std::flush;
	}
}
