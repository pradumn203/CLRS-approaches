#include <bits/stdc++.h>
using namespace std;

char** LCS_LENGTH(char x[],char y[]){
    int m = x.length();
    int n = y.length();
    char ** b = new char*[m + 1];
    for (int i=0; i<(m+1); i++){
        b[i] = new char [n+1];
        for(int j=0; j<(n+1); j++)
            b[i][j]=char(INT_MAX);
    }
    int[][] c = new int[m + 1][n + 1];

    for (int i = 1; i < m + 1; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++) {
        c[0][j] = 0;
    }
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\^';
            }
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '|^';
            }
            else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '-';
            }
        }
    }
    return b;
}

void PRINT_LCS(char b [][], char[] x, int i, int j){
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == '\\^') {
        printLCS(b, x, i - 1, j - 1);
        cout<<(x[i - 1]);
    }
    else if (b[i][j] == '|^') {
        printLCS(b, x, i - 1, j);
    }
    else {
        printLCS(b, x, i, j - 1);
    }
}

int main(){
    String a = "ABCBDAB";
    String b = "BDCABA";
    char x[a.size()];
    char y[b.size()];
    copy(a.begin(), a.end(), x);
    copy(b.begin(), b.end(), y);

    char[][] b = LCS_LENGTH(x, y);
    cout<<"Longest common subsequence of strings - "<<a<<" and "<<b<<": \n";
    PRINT_LCS(b, x, a.length(), b.length());
    cout<<"\n";
}


