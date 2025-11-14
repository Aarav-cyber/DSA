#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(int n) {
        int a[] = {1, 2, 5, 10};
        int count = 0;
        int x = sizeof(a) / sizeof(a[0]) - 1;   // last index
        int i = x;

        while (n > 0) {
            if (a[i] <= n) {
                n -= a[i];
                count++;
            } else {
                i--;
            }
        }
        return count;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter amount: ";
    cin >> n;

    int result = obj.findMin(n);

    cout << "Minimum number of coins = " << result << endl;

    return 0;
}
