#include <iostream>
using namespace std;

void main() {
	unsigned long long x = 256*256+10;
	unsigned long long* s = &x;
	unsigned char* c = reinterpret_cast<unsigned char*>(s);
	for (int i = 0; i < 8; i++) {
		cout << static_cast<int>(*(c + i)) << endl;
	}
}
