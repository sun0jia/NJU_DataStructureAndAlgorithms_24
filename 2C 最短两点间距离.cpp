#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
struct point {
	int x;
	int y;
};
bool compareX(point p1,point p2){
	return p1.x<p2.x;
}
bool compareY(point p1,point p2){
	return p1.y<p2.y;
}
double distance(const point& p1, const point& p2){
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
double closest(int left,int right,vector<point> &points)
{
	int mid=left+(right-left)/2;
	double d;
	if(right==left+2){
		d=min(distance(points[left],points[left+1]),distance(points[left+2],points[left+1]));
		d=min(d,distance(points[left],points[left+2]));
		return d;
	}
	if(right==left+1){
		return distance(points[left],points[right]);
	}
	d=min(closest(mid+1,right,points),closest(left,mid,points));
	vector<point> strip;
	for (int i = left; i <= right; i++) {
		if (abs(points[i].x - points[mid].x) < d) {
			strip.push_back(points[i]);
		}
	}
	sort(strip.begin(),strip.end(), compareY);
	for(int i=0;i<strip.size();i++){
		for(int j=i+1;j<strip.size();j++){
			if(abs(strip[i].x-strip[j].x)<d && abs(strip[i].y-strip[j].y)<d){
				double dis=distance(strip[i],strip[j]);
				d=min(d, dis);
			}//我服了这个地方是strip不是points 你在de什么de半天。。。。。
		}
	}
	return d;
}
int main(){
	int n;
	cin >> n;
	vector<point> points(n);
	for(int i=0;i<n;i++){
		cin >> points[i].x;
		cin >> points[i].y;
	}
	sort(points.begin(),points.end(),compareX);
	cout << setprecision(4)<< fixed<< closest(0,n-1,points);
	return 0;
}

