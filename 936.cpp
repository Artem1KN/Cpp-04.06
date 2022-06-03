#include <vector>
#include<algorithm>
#include<iostream>
#include <cmath>
#include<fstream>

using namespace std;

struct Point {
	int x;
	int y;
};

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int X0, Y0, n;
	double r;
	vector <Point> sp;
	fin >> X0 >> Y0 >> r >> n;
	for (int i = 0; i < n; ++i) {
		int x, y;
		fin >> x >> y;
		x -= X0;
		y -= Y0;
		if (sqrt(x * x + y * y) <= r) {
			sp.push_back(Point{x, y});
		}
	}
	int answer = 0;
	for (int i = 0; i < sp.size(); i++) {
		Point p1 = sp[i];
		int prov = 0;
		int l = 0; 
		int r = 0;
		for (int j = 0; j < sp.size(); j++) {
			Point p2 = sp[j];
			int cp = p1.x * p2.y - p2.x * p1.y;
			if (cp < 0) {
				l++;
			}
			else if (cp > 0) {
				r++;
			}
			else {
				prov++;
			}
		}
		if (answer > prov + l) {
			answer = max(answer, (prov + r));
		}
		else {
			answer = max((prov + l), (prov + r));
		}
	}
	fout << answer << endl;
}
