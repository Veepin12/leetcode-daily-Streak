
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort by (minimum - actual) ascending
        // Tasks with larger slack (min - act) go last
        // They demand high entry energy, so we tackle them when energy is highest
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
    if ((a[1] - a[0]) != (b[1] - b[0]))
        return (a[1] - a[0]) > (b[1] - b[0]); // larger slack first
    return a[1] > b[1];                         // tie-break: larger minimum first
});

        int initialEnergy = 0; // answer: minimum starting energy
        int currentEnergy = 0; // energy we'd have at this point in simulation

        for (auto& task : tasks) {
            int actual = task[0], minimum = task[1];

            // If current energy can't meet the minimum threshold,
            // we need more initial energy to cover the deficit
            if (currentEnergy < minimum) {
                initialEnergy += (minimum - currentEnergy);
                currentEnergy = minimum; // top up to exactly meet threshold
            }

            currentEnergy -= actual; // spend energy on this task
        }

        return initialEnergy;
    }
};
int main(){
    Solution S;
    vector<vector<int>> tasks = {{1,3},{5,3}};
    cout<<S.minimumEffort(tasks)<<endl;

    return 0;

}