#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the minimum number of platforms required at the station
int findPlatformOptimized(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();  // Total number of trains

    // Step 1: Sort both arrival and departure times
    // This helps us process all events (arrivals and departures) in chronological order
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platformsNeeded = 0;  // Current count of platforms in use
    int maxPlatforms = 0;     // Maximum platforms needed at any time
    int i = 0, j = 0;         // i tracks arrivals, j tracks departures

    // Step 2: Traverse both arrays
    // We’ll compare the next arrival and next departure in time order
    while (i < n && j < n) {

        // Case 1: A train arrives before the next one departs
        if (arr[i] <= dep[j]) {
            platformsNeeded++;  // Need a new platform for the arriving train
            i++;                // Move to the next arrival
        }
        // Case 2: The next train departs before another one arrives
        else {
            platformsNeeded--;  // One platform is now free
            j++;                // Move to the next departure
        }

        // Track the maximum number of platforms needed at any moment
        maxPlatforms = max(maxPlatforms, platformsNeeded);
    }

    // Step 3: Return the result
    return maxPlatforms;
}

int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    // Step 4: Create vectors to store arrival and departure times
    vector<int> arrival(n), departure(n);

    // Step 5: Input arrival times
    cout << "Enter arrival times (in 24-hour format, e.g., 900 for 9:00 AM):\n";
    for (int i = 0; i < n; i++) {
        cin >> arrival[i];
    }

    // Step 6: Input departure times
    cout << "Enter departure times (in 24-hour format, e.g., 910 for 9:10 AM):\n";
    for (int i = 0; i < n; i++) {
        cin >> departure[i];
    }

    // Step 7: Call the function to calculate the minimum platforms required
    int result = findPlatformOptimized(arrival, departure);

    // Step 8: Output the result
    cout << "\nMinimum number of platforms required = " << result << endl;

    return 0;
}
