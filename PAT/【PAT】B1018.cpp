#include <iostream>
using namespace std;
int main() {
	int js = 0, jp = 0, jf = 0; 
	int jchui = 0, jbu = 0, jjian = 0; 
	int ychui = 0, ybu = 0, yjian = 0; 
	char j, y;
	int n;
	cin >> n;
	while(n--) {
		cin >> j >> y;
		if(j == y) {
			jp++;
			if(j == 'C') {
				jchui++;
				ychui++;
			}
			if(j == 'B') {
				jbu++;
				ybu++;
			}
			if(j == 'J') {
				jjian++;
				yjian++;
			}
		} else if(j == 'C' && y == 'B') {
			jf++;
			jchui++;
			ybu++;
		} else if(j == 'C' && y == 'J') {
			js++;
			jchui++;
			yjian++;
		} else if(j == 'B' && y == 'C') {
			js++;
			jbu++;
			ychui++;
		} else if(j == 'B' && y == 'J') {
			jf++;
			jbu++;
			yjian++;
		} else if(j == 'J' && y == 'B'){
			js++;
			jjian++;
			ybu++;
		} else if(j == 'J' && y == 'C') {
			jf++;
			jjian++;
			ychui++;
		}
	}
	printf("%d %d %d\n", js, jp, jf);
	printf("%d %d %d\n", jf, jp, js);
	if(jbu > jchui) {
		if(jbu > jjian)
			cout << "B "; 
	} else if(jbu == jchui) {
		if(jbu >= jjian)
			cout << "B ";
		else
			cout << "J ";
	} else {
		if(jchui >= jjian)
			cout << "C ";
		else 
			cout << "J ";
	}
	if(ybu > ychui) {
		if(ybu > yjian)
			cout << "B"; 
	} else if(ybu == ychui) {
		if(ybu >= yjian)
			cout << "B";
		else
			cout << "J";
	} else {
		if(ychui >= yjian)
			cout << "C";
		else 
			cout << "J";
	}
	return 0;
}

