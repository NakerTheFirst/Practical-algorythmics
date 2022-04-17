#include <iostream>
#include <cmath>
using std:: cin, std:: cout, std::string, std::endl;

int main() {

    int gamesGS = 0;
    int gamesKS = 0;
    int G, T, A, D, X, Y, tmp, tmp1;
    
    cin >> G >> T >> A >> D;
    if (G < 1 || T < 1 || A < 1 || D < 1) return 0;
    for (int i = 1; T-i > 0; ++i) {
        gamesGS += T-i;
    }

    tmp1 = G*A+D;
    int x;
    for (int i = 1; ; ++i) {
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

    tmp = G*A+Y+D;
    while (tmp != 1) {
        tmp /= 2;
        gamesKS += tmp;
    }

    X = gamesGS * G + gamesKS;
    cout << X << "+" << Y;

    return 0;
}
