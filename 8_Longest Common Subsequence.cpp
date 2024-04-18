#include <iostream>
using namespace std;

void printLCS(string X, string Y, int m, int n, int L[][100]) {
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "Longest Common Subsequence: ";
    int k = 0;
    i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            cout << lcs[k];
            k++;
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            cout << "<- ";
            i--;
        } else {
            cout << "^|";
            j--;
        }
    }
    cout << endl;
}

int lcs(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    int c[m+1][100];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                c[i][j] = 0;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
            {
                if(c[i-1][j] > c[i][j-1])
                    c[i][j] = c[i-1][j];
                else
                    c[i][j] = c[i][j-1];
            }
        }
    }

    printLCS(X, Y, m, n, c);

    return c[m][n];
}

int main() {
    string S1 = "COMPUTER";
    string S2 = "REGISTER";

    cout << "Length of LCS is " << lcs(S1, S2);

    return 0;
}

