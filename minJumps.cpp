#include <iostream>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        // Step 1: Sieve up to max element
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; (long long)i * i <= maxVal; i++)
            if (isPrime[i])
                for (int j = i * i; j <= maxVal; j += i)
                    isPrime[j] = false;

        // Step 2: Build prime -> [indices] map
        // For each index j, for each prime factor p of nums[j], add j to primeMap[p]
        unordered_map<int, vector<int>> primeMap;
        for (int j = 0; j < n; j++) {
            int val = nums[j];
            // find all prime factors of val
            int temp = val;
            for (int p = 2; (long long)p * p <= temp; p++) {
                if (temp % p == 0 && isPrime[p]) {
                    primeMap[p].push_back(j);
                    while (temp % p == 0) temp /= p;
                }
            }
            if (temp > 1 && isPrime[temp])
                primeMap[temp].push_back(j);
        }

        // Step 3: BFS
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int jumps = 0;

        while (!q.empty()) {
            int sz = q.size();
            jumps++;
            while (sz--) {
                int i = q.front(); q.pop();

                // Adjacent steps
                for (int ni : {i - 1, i + 1}) {
                    if (ni < 0 || ni >= n) continue;
                    if (ni == n - 1) return jumps;
                    if (!visited[ni]) {
                        visited[ni] = true;
                        q.push(ni);
                    }
                }

                // Prime teleportation: if nums[i] itself is prime
                if (isPrime[nums[i]]) {
                    int p = nums[i];
                    if (primeMap.count(p)) {
                        for (int j : primeMap[p]) {
                            if (j == n - 1) return jumps;
                            if (!visited[j]) {
                                visited[j] = true;
                                q.push(j);
                            }
                        }
                        primeMap.erase(p); // KEY: never revisit this group
                    }
                }
            }
        }
        return -1; // unreachable (won't happen per constraints)
    }
};

int main(){
    Solution S;

    vector<int> nums = {2,3,4,7,9};
    cout<<S.minJumps(nums)<<endl;
    return 0;
}
