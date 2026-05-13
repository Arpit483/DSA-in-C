#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::vector<int> data = {1, 3, 2, 3, 2, 3, 4, 4, 4, 4,4,4,4,4,4,3};
    std::unordered_map<int, int> frequencies;

    for (int x : data) {
        frequencies[x]++;
    }

    for (auto const& [val, freq] : frequencies) {
        std::cout << val << ": " << freq << std::endl;
    }
    return 0;
}
