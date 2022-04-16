#include <iostream>
#include <cmath>
using namespace std;

// Declare the function
string penalty(int G, int T, int A, int D);

int main() {

    penalty(8, 4, 2, 0);

    return 0;
}

// G = Groups number
// T = Teams in each group
// A = Advancing teams from each group
// D = Directly advancing number of teams

// Define the function
string penalty(int G, int T, int A, int D) {

    // Check G input correctness
    if(G <= 0 || G > pow(2, 16)) {
        cout << "Input error: G must be greater than 0 and smaller than 65536" << endl;
        return "Input error in G";
    }

    // Check T input correctness
    if(T < A || T > pow(2, 16)) {
        cout << "Input error: T must be greater or equal than A and smaller than 65536" << endl;
        return "Input error in T";
    }

    // Check A input correctness
    if(A <= 0 || A > pow(2, 16)) {
        cout << "Input error: A must be greater than 0 and smaller than 65536" << endl;
        return "Input error in A";
    }

    // Check D input correctness
    if(D > pow(2, 16)) {
        cout << "Input error: D must be smaller than 65536" << endl;
        return "Input error in D";
    }

    // Declare games counting variables
    int groupGames = 0;
    int knoGames = 0;
    int totGames = groupGames + knoGames;

    // Group stage games
    for(int i = 1; i+1 <= T; ++i) {
        int temp = G * (T-i);
        groupGames += temp;
    }

    cout << "The number of group phase games is: " << groupGames << endl;

    // HERE I LEAVE
    // Then add teams to the knockout stage to ceil their number to the power of 2
    // Check if the number of teams is a power of 2
    for(int i = 2; (G*A) % 2 != 0 && i < pow(2,16);) {

    }

    // Knockout stage games
    // DYNAMISE THIS
    knoGames = (G*A/2) + (G*A/4) + (G*A/8) + G*A/16;

    // Print results
    cout << "The number of knockout phase games is: " <<  knoGames << endl;
    cout << "The total number of games is: " << totGames << endl;

    // Calculate number of added teams

    return "nothing";
}