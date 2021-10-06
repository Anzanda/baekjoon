#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"


int main(void) {
	FastIO;
	string name;
	cin >> name;
	int idx = -1;
	for(int i=0; i<(int)name.length(); i++) {
		if(name[i] == '.') {
			idx = i;
			break;
		}
	}
	for(int i=idx+1; i<(int)name.length(); i++) {
		if(name[i] < 'a') {
			name[i] += 32;
		}
	}
	set<string> image;
	image.insert("jpeg");
	image.insert("jpg");
	image.insert("gif");
	image.insert("png");
	image.insert("bmp");
	cout << (image.find(name.substr(idx+1)) != image.end()) << endl;
	return 0;
}
