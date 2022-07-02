#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {

    struct {
        int gamesGS, gamesKS;
        int G, T, A, D, X, Y;
        bool error;
    } penData1{}, penData2{}, penData3{};

    // Auxiliary variables
    int x;
    int temp, tmp1, tmp2, tmp3;

    // Initialise error to false{}
    penData1.error = false;
    penData2.error = false;
    penData3.error = false;

    // Take input
    cin >> penData1.G >> penData1.T >> penData1.A >> penData1.D;
    cin >> penData2.G >> penData2.T >> penData2.A >> penData2.D;
    cin >> penData3.G >> penData3.T >> penData3.A >> penData3.D;

    // Check for input errors
    if (penData1.G < 1 || penData1.T < 1 || penData1.A < 1 || penData1.D < 0) penData1.error = true;
    if (penData2.G < 1 || penData2.T < 1 || penData2.A < 1 || penData2.D < 0) penData2.error = true;
    if (penData3.G < 1 || penData3.T < 1 || penData3.A < 1 || penData3.D < 0) penData3.error = true;

    // Calculate group stage games
    for (int i = 1; penData1.T-i > 0; ++i) {
        penData1.gamesGS += penData1.T-i;
    }

    for (int i = 1; penData2.T-i > 0; ++i) {
        penData2.gamesGS += penData2.T-i;
    }

    for (int i = 1; penData3.T-i > 0; ++i) {
        penData2.gamesGS += penData3.T-i;
    }

    // Calculate Ys
    temp = penData1.G * penData1.A + penData1.D;
    for (int i = 1;; ++i) {
        x = pow(2, i);
        if (temp == x) {
            penData1.Y = 0;
            break;
        }
        if (temp < x) {
            penData1.Y = pow(2, i) - temp;
            break;
        }
    }

    temp = penData2.G * penData2.A+ penData2.D;
    for (int i = 1;; ++i) {
        x = pow(2, i);
        if (temp == x) {
            penData2.Y = 0;
            break;
        }
        if (temp < x) {
            penData2.Y = pow(2, i) - temp;
            break;
        }
    }

    temp = penData3.G * penData3.A+ penData3.D;
    for (int i = 1;; ++i) {
        x = pow(2, i);
        if (temp == x) {
            penData3.Y = 0;
            break;
        }
        if (temp < x) {
            penData3.Y = pow(2, i) - temp;
            break;
        }
    }

    // Calculate knockout stage games
    tmp1 = penData1.G * penData1.A + penData1.Y + penData1.D;
    tmp2 = penData2.G * penData2.A + penData2.Y + penData2.D;
    tmp3 = penData3.G * penData3.A + penData3.Y + penData3.D;

    while (tmp1 != 1) {
        tmp1 /= 2;
        penData1.gamesKS += tmp1;
    }

    while (tmp2 != 1) {
        tmp2 /= 2;
        penData2.gamesKS += tmp2;
    }

    while (tmp3 != 1) {
        tmp3 /= 2;
        penData3.gamesKS += tmp3;
    }

    penData1.X = penData1.gamesGS * penData1.G + penData1.gamesKS;
    penData2.X = penData2.gamesGS * penData2.G + penData2.gamesKS;
    penData3.X = penData3.gamesGS * penData3.G + penData3.gamesKS;

    // Print the output if no errors are detected
    if (!penData1.error) {
        cout << penData1.G << "*" << penData1.A << "/" << penData1.T << "+" << penData1.D;
        cout << "=" << penData1.X << "+" << penData1.Y << endl;
    }

    if (!penData2.error) {
        cout << penData2.G << "*" << penData2.A << "/" << penData2.T << "+" << penData2.D;
        cout << "=" << penData2.X << "+" << penData2.Y << endl;
    }

    if (!penData3.error) {
        cout << penData3.G << "*" << penData3.A << "/" << penData3.T << "+" << penData3.D;
        cout << "=" << penData3.X << "+" << penData3.Y << endl;
    }

    return 0;
}