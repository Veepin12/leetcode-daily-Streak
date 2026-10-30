//
//  Shortest_path.cpp
//  DSA_with_cpp
//
//  Created by Veepin kumar on 30/10/26.
//

/*
 You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi.

 You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.

 Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.

  

 Example 1:

 Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1

 Output: 3

 Explanation:

 The optimal valid path from node 0 to node 2 is as follows:

 Use edges[2] = [0, 2, 3] to reach node 2 with a weight wi = 3.
 The corresponding concatenation of labels is "ab", which satisfies at most k = 1 consecutive identical characters. Thus, the answer is 3.
 Example 2:

 Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 2

 Output: 2

 Explanation:

 The optimal valid path from node 0 to node 2 is as follows:

 Use edges[0] = [0, 1, 1] to reach node 1 with weight wi = 1.
 Use edges[1] = [1, 2, 1] to reach node 2 with weight wi = 1.
 The corresponding concatenation of labels is "aab", which satisfies at most k = 2 consecutive identical characters. Thus, the answer is 2.
 Example 3:

 Input: n = 3, edges = [[0,1,1],[1,2,1]], labels = "aaa", k = 2

 Output: -1

 Explanation:

 There is no valid path from node 0 to node 2 that satisfies at most k = 2 consecutive identical characters. Thus, the answer is -1.

  

 Constraints:

 1 <= n == labels.length <= 5 * 104
 0 <= edges.length <= 5 * 104
 edges[i] == [ui, vi, wi]
 0 <= ui, vi <= n - 1
 ui != vi
 1 <= wi <= 104
 labels consists of lowercase English letters
 1 <= k <= 50
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges)
            graph[e[0]].emplace_back(e[1], e[2]);

        vector<int> best(n, k + 1);  // best[x]: the shortest run x was settled with, k + 1 until then
        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<>> heap;  // (distance, run, node): the walk ends with run nodes labeled labels[node]
        heap.emplace(0, 1, 0);
        while (!heap.empty()) {
            auto [d, run, x] = heap.top();
            heap.pop();
            if (run >= best[x])  // x was settled before, no farther away and with a run no longer
                continue;
            if (x == n - 1)
                return d;
            best[x] = run;
            for (auto [y, w] : graph[x]) {
                int r = labels[y] == labels[x] ? run + 1 : 1;
                if (r < best[y])
                    heap.emplace(d + w, r, y);
            }
        }
        return -1;
    }
};
int main(){
    return 0;
}
