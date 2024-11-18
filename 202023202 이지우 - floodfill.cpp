xj#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

char block[10][10];

int WBconvert(int x, int y) {
	int tmp = 0;
	if (block[x][y] == 'w') {
		block[x][y] = 'b';
		tmp += 1;
		tmp += WBconvert(x + 1, y);
		tmp += WBconvert(x - 1, y);
		tmp += WBconvert(x, y + 1);
		tmp += WBconvert(x, y - 1);
	}
	return tmp;
}

void floodfill() {
	int time = 0;
	vector<int> area;
	int cell;

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cell = WBconvert(i, j);
			if (cell != 0) {
				area.push_back(cell);
				time++;
			}
		}
	}

	cout << time << " white areas of ";
	for (int i = 0; i < area.size(); i++) {
		if (area[i] != 0) {
			if (i == (area.size() - 1)) cout << "and " << area[i] << " cells." << endl;
			else cout << area[i] << ", ";
		}
	}
}

int main(void) {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == 0 || i == 9 || j == 0 || j == 9) block[i][j] = 'b';
			else {
				if (rand() % 2 == 0) block[i][j] = 'b';
				else block[i][j] = 'w';
			}
		}
	}

	for (int i = 1; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			cout << block[i][j] << " ";
		}
		cout << "" << endl;
	}
	
	floodfill();
}