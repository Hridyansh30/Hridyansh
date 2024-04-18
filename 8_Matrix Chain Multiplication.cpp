#include <iostream>
#include <climits>
using namespace std;

void print(int i, int j, int s[][4], char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    print(i, s[i][j], s, name);
    print(s[i][j] + 1, j, s, name);
    cout << ")";
}

void MatrixChainOrder(int p[], int n) {
    int m[n][n];
    int s[4][4];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
    char name = 'A';
    cout << "Optimal Parenthesization: ";
    print(1, n - 1, s, name);
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    MatrixChainOrder(arr, N);
    return 0;
}

