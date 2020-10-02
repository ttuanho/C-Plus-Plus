/**
 * \file
 * \author [Tuan Ho](http://github.com/ttuanho)
 * \author [Abhishek Jain](https://github.com/Abhi13027)
 * \brief [Longest Bitonic
 * Sequence](https://www.techiedelight.com/longest-bitonic-subsequence/)
 *
 */

#include <iostream>
#include <vector>


int LBS(std::vector<int> ar, int n) {
    int i = 0, j = 0;
    std::vector<int> lis(n);
    for (i = 0; i < n; i++) {
        lis.at(i) = 1;
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (ar[i] > ar[j] && lis.at(i) < lis.at(j) + 1) {
                lis.at(i) = lis.at(j) + 1;
            }
        }
    }

    std::vector<int> lds(n);
    for (i = 0; i < n; i++) {
        lds.at(i) = 1;
    }

    for (i = n - 2; i >= 0; i--) {
        for (j = n - 1; j > i; j--) {
            if (ar[i] > ar[j] && lds.at(i) < lds.at(j) + 1) {
                lds.at(i) = lds.at(j) + 1;
            }
        }
    }
    int max_result = lis.at(0) + lds.at(0) - 1;
    for (i = 1; i < n; i++) {
        if (lis.at(i) + lds.at(i) - 1 > max_result) {
            max_result = lis.at(i) + lds.at(i) - 1;
        }
    }

    return max_result;
}
int main() {
    int n = 0;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> ar(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> ar[i];
    }

    std::cout << LBS(ar, n) << std::endl;
    return 0;
}
