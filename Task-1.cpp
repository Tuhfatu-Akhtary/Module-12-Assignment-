int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    // Sort the boxTypes based on the number of units per box in descending order
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });

    int total_units = 0;

    for (const auto& boxType : boxTypes) {
        int boxes = boxType[0];       // Number of boxes of this type
        int units_per_box = boxType[1]; // Units per box of this type
        
        if (truckSize == 0) {
            break; // If the truck is full, we can stop
        }

        // Determine how many boxes to take
        int boxes_to_take = min(boxes, truckSize);
        total_units += boxes_to_take * units_per_box; // Calculate total units
        truckSize -= boxes_to_take; // Update remaining truck size
    }

    return total_units;
}

Time Complexity: O(nlogn)
Space Complexity: O(1)