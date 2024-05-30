public class Solution {
    public int CountTriplets(int[] arr) {
int n = arr.Length;
        int count = 0;
        int[] prefixXor = new int[n + 1];
        
        // Calculate prefix XOR
        for (int i = 0; i < n; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        }
        
        // Find all triplets (i, j, k) where a == b
        for (int i = 0; i < n; i++) {
            for (int k = i + 1; k < n; k++) {
                if (prefixXor[i] == prefixXor[k + 1]) {
                    count += (k - i);
                }
            }
        }
        
        return count;
    }
}