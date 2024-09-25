int maxDisjointIntervals(vector<vector<int>>& intervals) {
    // Sort the intervals by their end times
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int count = 0;  // To count the number of disjoint intervals
    int last_end_time = INT_MIN;  // Initialize last end time to the minimum integer

    for (const auto& interval : intervals) {
        int start = interval[0];
        int end = interval[1];

        // If the current interval starts after the last selected interval ends
        if (start > last_end_time) {
            count++;  // Select this interval
            last_end_time = end;  // Update the end time
        }
    }

    return count;
}

Time Complexity: O(nlogn)
Space Complexity: O(1)
