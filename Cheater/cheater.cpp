#include <iostream>
#include <vector>

using std::cin;
using std::cout;


class Cards {
public:
    std::vector<char> cardName;
    unsigned int cardValue;
    unsigned int cardSuit;
};


int main() {

    int N, k;
    char cNameByChar;
    Cards cardsObj;

    // Take the number of test cases
    cin >> N;

    // Take the number of cards per player and check its correction
    cin >> k;
    if (k < 0 || k > 26) return 0;

    // Take card names
    for (int i = 0; i < k*4; ++i) {
        cin >> cNameByChar;
        cardsObj.cardName.push_back(cNameByChar);
    }

    // Print output for debugging
    for (int i = 0; i <= k*2; i+=2) {
        cout << cardsObj.cardName[i];
        cout << cardsObj.cardName[i+1] << "\n";
    }

    return 0;
}
