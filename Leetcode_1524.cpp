
#define MOD 1000000007  // Define modulo
int numOfSubarrays(int* arr, int arrSize) {
    int oddCount = 0, evenCount = 1; 
    long long prefixSum = 0, count = 0;  
for (int i = 0; i < arrSize; i++) {
        prefixSum += arr[i];
if (prefixSum % 2 != 0) {
            count = (count + evenCount) % MOD;
            oddCount++;
        } else {
            count = (count + oddCount) % MOD;
            evenCount++;
        }
    }
return count;
}
