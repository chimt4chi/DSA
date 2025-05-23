#include <iostream>
#include <string>
using namespace std;

// Recursive function to find LCS
int lcs(string s1, string s2, int lenI, int lenJ) {
    if (lenI == 0 || lenJ == 0) {
        return 0;
    }

    if (s1[lenI - 1] == s2[lenJ - 1]) {
        return 1 + lcs(s1, s2, lenI - 1, lenJ - 1);
    }

    else {
        return max(
            lcs(s1, s2, lenI - 1, lenJ),
            lcs(s1, s2, lenI, lenJ - 1)
        );
    }
}

int main() {
    string s1 = "aman";
    string s2 = "amin";

    int result = lcs(s1, s2, s1.size(), s2.size());

    cout << "Length of LCS: " << result << endl;

    return 0;
}
