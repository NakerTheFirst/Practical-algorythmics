#include <iostream>
#include <cmath>
using std:: cin, std:: cout, std::string, std::endl;

int GS(int T);
int Y(int G, int A, int D);
int KS(int G, int A, int Y, int D);
int X(int gamesGS, int gamesKS, int G);

int main() {

    int gamesGS = 0;
    int gamesKS = 0;
    int G, T, A, D, X, Y, x, tmp, tmp1;

    // Take input
    cin >> G >> T >> A >> D;

    // Check for input errors
    if (G < 1 || T < 1 || A < 1 || D < 1) return 0;

    // Calculate group stage games
    for (int i = 1; T-i > 0; ++i) {
        gamesGS += T-i;
    }

    // Calculate Y
    tmp1 = G*A+D;
    for (int i = 1;; ++i) {
        x = pow(2, i);
        if (tmp1 == x) {
            Y = 0;
            break;
        }
        if (tmp1 < x) {
            Y = pow(2, i) - tmp1;
            break;
        }
    }

    // Calculate knockout stage games
    tmp = G*A+Y+D;
    while (tmp != 1) {
        tmp /= 2;
        gamesKS += tmp;
    }

    X = gamesGS * G + gamesKS;

    // Print the output
    cout << X << "+" << Y;

    return 0;
}

int GS(int T) {
    int gamesGS = 0;
    for (int i = 1; T-i > 0; ++i) {
        gamesGS += T-i;
    }
    return gamesGS;
}

int Y(int G, int A, int D) {
    int Y;
    int tmp1 = G*A+D;
    for (int i = 1;; ++i) {
        int x = pow(2, i);
        if (tmp1 == x) {
            Y = 0;
            break;
        }
        if (tmp1 < x) {
            Y = pow(2, i) - tmp1;
            break;
        }
    }
    return Y;
}

int KS(int G, int A, int Y, int D) {
    int tmp = G*A+Y+D;
    int gamesKS = 0;
    while (tmp != 1) {
        tmp /= 2;
        gamesKS += tmp;
    }
    return gamesKS;
}

int X(int gamesGS, int gamesKS, int G) {
    return gamesGS * G +  gamesKS;
}