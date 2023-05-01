#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void MakeHistogramGraph(map <char, int>& Histogram, string& LowHistogram, int& MaxValHistogram) {

	while (true) {

		for (char ch : LowHistogram) {
			if (Histogram[ch] == MaxValHistogram) {
				cout << '#';
				--Histogram[ch];
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';

		--MaxValHistogram;
		if (MaxValHistogram == 0) {return;}
	}

}

int main() {

	// input
	map <char, int> Histogram;
	char ch;

	while (cin >> ch) {
		if (ch != ' ' && ch != '\n') {
			++Histogram[ch];
		}
	}

	//sol and output
	int MaxValHistogram = 0;
	string LowHistogram;
	for (auto [ch, count] : Histogram) {
		LowHistogram += ch;
		MaxValHistogram = max(MaxValHistogram, count);
	}

	MakeHistogramGraph(Histogram, LowHistogram, MaxValHistogram);
	cout << LowHistogram;
}
