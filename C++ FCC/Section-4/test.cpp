#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

void solve() {
    // C++17 Structured Binding example:
    map<int, string> m = {{1, "Start DSA"}};
    for (auto const& [id, status] : m) {
        cout << id << ": " << status << endl;
    }
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while(t--) {
        solve();
    }
    return 0;
}
