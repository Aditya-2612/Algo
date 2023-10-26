#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's safe to place a queen at a specific row and column
bool isSafe(int row, int col, vector<int>& solution) {
    for (int i = 0; i < row; i++) {
        // Check if there is a queen in the same column or on the same diagonal
        if (solution[i] == col || abs(i - row) == abs(solution[i] - col)) {
            return false;
        }
    }
    return true;
}

// Backtracking function to find all solutions to the N-Queens problem
void solveNQueens(int n, int row, vector<int>& solution, vector<vector<string>>& results) {
    // If all queens are placed, a valid solution is found
    if (row == n) {
        // Create a chessboard with the current solution and add it to the results
        vector<string> result(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            result[i][solution[i]] = 'Q';
        }
        results.push_back(result);
        return;
    }

    // Try placing a queen in each column in the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, solution)) {
            // If it's safe to place a queen, update the solution and recursively solve the next row
            solution[row] = col;
            solveNQueens(n, row + 1, solution, results);
            solution[row] = -1;  // Backtrack by resetting the column to -1
        }
    }
}

// Main function to solve the N-Queens problem and display the solutions
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> results;
    vector<int> solution(n, -1);  // Initialize the solution with -1
    solveNQueens(n, 0, solution, results);
    return results;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    if (solutions.empty()) {
        cout << "No solutions found for N = " << n << endl;
    } else {
        // Display the solutions
        for (vector<string>& solution : solutions) {
            for (string row : solution) {
                cout << row << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
