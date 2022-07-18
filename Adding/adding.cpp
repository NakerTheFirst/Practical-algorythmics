#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// Remove trailing zeros
int handle_trailing_zeros(int num) {
    int num_without_trailing_zeros;

    // If the last digit is not 0, return num

    return num_without_trailing_zeros;
}

int reverse_number(int num) {
    if (num < 10 && num > 0) return num;

    int reversed_num = 0;
    int n, remainder;

    while(num != 0) {
        remainder = num % 10;
        reversed_num = reversed_num * 10 + remainder;
        num /= 10;
    }

    return reversed_num;
}

int main() {

    int N, num1, num2, sum, iter = 0;
    std::vector<int> nums;

    // Take number of test cases
    cin >> N;

    // Take numbers to reverse
    for (int i = 0; i < N; ++i) {
        cin >> num1 >> num2;
        nums.push_back(num1);
        nums.push_back(num2);
    }

    // Overwrite the numbers in nums with their reversed versions
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] = reverse_number(nums[i]);
    }

    // Print the desired output
    for (int i = 0; i < N; ++i) {
        sum = nums[iter] + nums[iter+1];
        cout << reverse_number(sum) << "\n";
        iter++;
        iter++;
    }

    return 0;
}
