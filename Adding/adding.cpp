#include <iostream>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;

// Utility function - remove trailing zeros
int handle_trailing_zeros(int num) {
    int num_without_trailing_zeros;

    // code

    return num_without_trailing_zeros;
}

int reverse(int num) {
    int reversed_num;

    // code

    return reversed_num;
}

int main() {

    int N;
    int num1, num2;
    std::vector<int> nums;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> num1 >> num2;
        nums.push_back(num1);
        nums.push_back(num2);
    }

    // Print the output
    for (int i = 0; i < 2*N; ++i) {
        cout << "Pair: " << nums[i] << ", " << nums[i+1] << "\n";
        ++i;
    }

    return 0;
}
