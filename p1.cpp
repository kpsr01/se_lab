#include <iostream>
#include <vector>
using namespace std;

/**
 * Matrix Folding Program
 * This program folds a matrix by multiplying symmetric elements
 * both horizontally and vertically, reducing the matrix size.
 */
int main() {
    int N;
    cout << "Enter the size of the matrix (N): ";
    cin >> N;
    
    // Input validation
    if (N <= 0) {
        cout << "Error: Matrix size must be positive." << endl;
        return 1;
    }
    
    // Initialize the input matrix
    vector<vector<int>> matrix(N, vector<int>(N));
    cout << "\nEnter the elements of the matrix:\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Step 1: Horizontal folding - multiply symmetric rows
    vector<vector<int>> horizontalFold;
    int halfRows = N / 2;
    
    for (int i = 0; i < halfRows; i++) {
        vector<int> row(N);
        for (int j = 0; j < N; j++) {
            row[j] = matrix[i][j] * matrix[N - 1 - i][j];
        }
        horizontalFold.push_back(row);
    }
    
    // If odd number of rows, include the middle row as is
    if (N % 2 == 1) {
        horizontalFold.push_back(matrix[N / 2]);
    }
    
    // Step 2: Vertical folding - multiply symmetric columns
    vector<vector<int>> result;
    for (auto &row : horizontalFold) {
        vector<int> newRow;
        for (int j = 0; j < N / 2; j++) {
            newRow.push_back(row[j] * row[N - 1 - j]);
        }
        // If odd number of columns, include the middle column as is
        if (N % 2 == 1) {
            newRow.push_back(row[N / 2]);
        }
        result.push_back(newRow);
    }
    
    // Display the result
    cout << "\nResultant folded matrix:\n\n";
    for (auto &row : result) {
        for (size_t j = 0; j < row.size(); j++) {
            if (j) cout << ' ';
            cout << row[j];
        }
        cout << '\n';
    }
    
    return 0;
}