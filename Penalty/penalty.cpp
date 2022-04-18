#include <iostream>
#include <cmath>
using std:: cin, std:: cout, std::string, std::endl;

int main() {

    int gamesGS = 0;
    int gamesKS = 0;
    int G, T, A, D, X, Y;
    int x, temp, temp1;

    // Take input
    cin >> G >> T >> A >> D;

    // Check for input errors
    if (G < 1 || T < 1 || A < 1 || D < 0) return 0;

    // Calculate group stage games
    for (int i = 1; T-i > 0; ++i) {
        gamesGS += T-i;
    }

    // Calculate Y
    temp1 = G*A+D;
    for (int i = 1;; ++i) {
        x = pow(2, i);
        if (temp1 == x) {
            Y = 0;
            break;
        }
        if (temp1 < x) {
            Y = pow(2, i) - temp1;
            break;
        }
    }

    // Calculate knockout stage games
    temp = G*A+Y+D;
    while (temp != 1) {
        temp /= 2;
        gamesKS += temp;
    }

    X = gamesGS * G + gamesKS;

    // Print the output
    cout << X << "+" << Y;

    return 0;
}
