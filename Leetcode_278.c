// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2; // Avoid integer overflow
        if (isBadVersion(mid)) {
            right = mid; // Move left if mid is bad
        } else {
            left = mid + 1; // Move right if mid is good
        }
    }
    return left; // First bad version
}

