#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cout << "Enter the size of the matrix (N): ";
	cin>>N;
	vector<vector<int >> a(N, vector<int >(N));
	cout << "\nEnter the elements of the matrix:\n\n";
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++) cin >> a[i][j];
	}

	vector<vector<int >> horiz;
	int halfRows = N/2;
	for(int i=0;i<halfRows;i++) {
		vector<int > row(N);
		for(int j=0;j<N;j++) row[j] = a[i][j] * a[N-1-i][j];
		horiz.push_back((row));
	}
	if(N % 2 == 1) {
		horiz.push_back(a[N/2]);
	}

	vector<vector<int >> result;
	for(auto &row : horiz) {
		vector<int > newRow;
		for(int j=0;j<N/2;j++) {
			newRow.push_back(row[j] * row[N-1-j]);
		}
		if(N % 2 == 1) newRow.push_back(row[N/2]);
		result.push_back((newRow));
	}

	cout << "\nResultant folded matrix:\n\n";
	for(auto &row : result){
		for(int j=0;j<row.size();j++) {
			if(j) cout << ' ';
			cout << row[j];
		}
		cout << '\n';
	}
	return 0;
}