#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using namespace std;

class Solution {
    /*
     * CORE IDEA
     * ─────────
     * 1. Unroll the square boundary clockwise into a 1-D perimeter position.
     *    Manhattan distance between any two boundary points == their shorter
     *    arc distance along the perimeter  (provable via the |x1-x2|+|y1-y2|
     *    identity on each edge pair).
     *
     * 2. Binary-search on the answer d.
     *
     * 3. Feasibility check via greedy + binary lifting:
     *    - nxt[i]      = first index reachable from i with gap >= d  (O(n) two-pointer)
     *    - lift[j][i]  = index after 2^j greedy hops from i          (O(n log n) build)
     *    - For each start, jump k-1 times using the sparse table,
     *      then verify the wrap-around gap.                            (O(k log n) per start)
     *    Total per binary-search step: O(n * k * log n)
     *    Since k <= 25 and log n < 14, this is effectively O(n) per step.
     *
     * 4. Wrap-around trick: work on a DOUBLED array
     *    pos[i+n] = pos[i] + perimeter  so all index arithmetic is linear.
     */

    static constexpr int LOG = 15;   // 2^15 > 15000 (max n)

    /* Map (x,y) on the square boundary to clockwise perimeter distance from (0,0).
     *   Bottom edge  (0,0)->(side,0) : pos = x
     *   Right  edge  (side,0)->(side,side) : pos = side + y
     *   Top    edge  (side,side)->(0,side) : pos = 2*side + (side-x)
     *   Left   edge  (0,side)->(0,0)       : pos = 3*side + (side-y)
     */
    static long long toPos(int x, int y, int side) {
        if (y == 0)      return x;
        if (x == side)   return (long long)side + y;
        if (y == side)   return 2LL * side + (side - x);
        /* x == 0 */     return 3LL * side + (side - y);
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        long long P = 4LL * side;          // full perimeter

        /* ── Step 1: linearise & sort ─────────────────────────────────────── */
        vector<long long> pos(n);
        for (int i = 0; i < n; i++)
            pos[i] = toPos(points[i][0], points[i][1], side);
        sort(pos.begin(), pos.end());

        /* Doubled array to handle wrap-around without branching.
         * pos2[i+n] = pos[i] + P                                            */
        int N2 = 2 * n;
        vector<long long> pos2(N2);
        for (int i = 0; i < n; i++) {
            pos2[i]     = pos[i];
            pos2[i + n] = pos[i] + P;
        }

        /* ── Step 2: binary search on answer d ────────────────────────────── */
        long long lo = 1, hi = 2LL * side, ans = 0;

        /* Sparse table: lift[j][i] stores the index we reach after 2^j hops
         * starting at i, in the doubled pos2[] array.
         * Indices are in [0, 2n).
         * Allocated once outside the binary search loop.                     */
        vector<array<int, 15>> lift(N2);   // lift[i][j]

        while (lo <= hi) {
            long long d = lo + (hi - lo) / 2;

            /* ── Build nxt[] with two pointers ──────────────────────────── */
            /* nxt[i] = smallest index j in pos2[] (j > i) with
             *          pos2[j] - pos2[i] >= d.
             * We only need i in [0, 2n) and j in [i+1, 2n].
             * j == 2n means "no valid next within the doubled array."        */
            vector<int> nxt(N2, N2);
            {
                int j = 1;
                for (int i = 0; i < N2; i++) {
                    if (j <= i) j = i + 1;        // j strictly ahead of i
                    while (j < N2 && pos2[j] - pos2[i] < d) j++;
                    nxt[i] = j;                   // may equal N2 (sentinel)
                }
            }

            /* ── Build binary lifting table ─────────────────────────────── */
            /* lift[i][0] = nxt[i]
             * lift[i][j] = lift[ lift[i][j-1] ][j-1]
             * Out-of-range indices (>= N2) stay at N2 (sentinel).          */
            for (int i = 0; i < N2; i++) lift[i][0] = nxt[i];
            for (int j = 1; j < LOG; j++)
                for (int i = 0; i < N2; i++) {
                    int mid = lift[i][j - 1];
                    lift[i][j] = (mid < N2) ? lift[mid][j - 1] : N2;
                }

            /* ── Greedy feasibility check ───────────────────────────────── */
            /* For each starting index s in [0, n):
             *   Jump exactly (k-1) times using the lift table.
             *   After the jumps, cur is the index of the (k-th) selected point.
             *   The selection is valid iff:
             *     (a) cur < n + s  (still within one full wrap around from s)
             *     (b) The "wrap gap" from cur back to s is >= d:
             *         pos2[s] + P - pos2[cur] >= d
             *         i.e. pos2[s + n] - pos2[cur] >= d
             *
             *   We do the (k-1) jumps in O(log k) using binary decomposition. */
            bool feasible = false;
            for (int s = 0; s < n && !feasible; s++) {
                int cur = s;

                /* Decompose (k-1) into powers of 2 and apply lifts. */
                int hops = k - 1;
                for (int j = LOG - 1; j >= 0; j--) {
                    if ((hops >> j) & 1) {
                        cur = lift[cur][j];
                        if (cur >= N2) break;     // overshot, no point trying
                    }
                }

                if (cur >= N2) continue;          // couldn't place k points

                /* cur is the index of the k-th point.
                 * It must be in [s+1, s+n-1] (at most one full loop).
                 * Then the wrap-around gap must be >= d.                    */
                if (cur < s + n && pos2[s + n] - pos2[cur] >= d)
                    feasible = true;
            }

            if (feasible) { ans = d; lo = d + 1; }
            else            hi = d - 1;
        }

        return (int)ans;
    }
};
int main(){

    int side = 2;
    vector<vector<int>> points = {{1,2},{0,1},{0,2},{2,2}};
    int  k = 2;

    Solution S;
    cout<<S.maxDistance(side,points,k)<<endl;
    return 0;
}