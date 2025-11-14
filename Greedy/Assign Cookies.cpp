#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0; // child index
        int j = 0; // cookie index
        int count = 0;
        
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {  
                count++;
                i++;
                j++;
            } else {
                j++;  // current cookie too small, try next one
            }
        }
        
        return count;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> g = {1, 2, 3};      // greed factor of children
    vector<int> s = {1, 1};         // sizes of cookies

    int result = obj.findContentChildren(g, s);

    cout << "Number of satisfied children = " << result << endl;

    return 0;
}
