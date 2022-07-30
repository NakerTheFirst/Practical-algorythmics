#include <iostream>
#include <vector>

using std::cin;
using std::cout;

// TODO: Convert card names to values
// TODO:

class Cards {
public:
    std::vector<char> cardName;
    unsigned int cardValue;
    unsigned int cardSuit;

    // Utility method
    void printCardsNames(Cards cardsObj) {
        for (int i = 0; i < cardsObj.cardName.size(); ++i) {
            if (i % 2 == 0 && i != 0) cout << "\n";
            cout << cardsObj.cardName[i];
        }
    }
};


int main() {

    int N, k, iter = 0;
    char cNameByChar;
    bool close = false;
    Cards AdamCards;
    Cards EveCards;

    // Number of test cases
    cin >> N;

    // Input taking loop
    while (!close) {

        // Number of cards per player
        cin >> k;
        if (k < 0 || k > 26) return 0;

        // Take Adam's cards names
        for (int i = 0; i < k*2; ++i) {
            cin >> cNameByChar;
            AdamCards.cardName.push_back(cNameByChar);
        }

        // Take Eve's cards names
        for (int i = k*2; i < k*4; ++i) {
            cin >> cNameByChar;
            EveCards.cardName.push_back(cNameByChar);
        }

        iter++;
        if (iter == N) close = true;
    }

    cout << "Adam's cards: \n";
    AdamCards.printCardsNames(AdamCards);

    cout << "\nEve's cards: \n";
    EveCards.printCardsNames(EveCards);

    return 0;
}
