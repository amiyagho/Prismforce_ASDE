#include <iostream>
#include <vector>
using namespace std;

bool canAbhimanyuCross(vector<int> enemies, int p, int a, int b) {
    int n = enemies.size();
    vector<bool> regenerated(n, false);
    int initialPower = p;

    for (int i = 0; i < n; ++i) {
        // Check for regeneration of k3 and k7 
        if ((i == 2 || i == 6) && !regenerated[i]) {
            enemies[i] = enemies[i] / 2; 
            regenerated[i] = true;
        }

        // Recharge if Abhimanyu has recharges available And needs a recharge
        if (b > 0 && p < enemies[i]) { // Check if recharge is needed HERE
            p = initialPower; 
            b--;
        }

        // Skip an enemy if Abhimanyu has skips available
        if (a > 0) {
            a--;
            continue;
        }

        // check if Abhimanyu's power is sufficient (after potential regeneration)
        if (p < enemies[i]) {
            return false;
        }

        // Abhimanyu wins the fight
        p -= enemies[i]; 
    }

    return true; // Abhimanyu crossed all circles successfully
}

int main() {
    // test case 1
    vector<int> enemies1 = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
    int p1 = 100;
    int a1 = 2;
    int b1 = 1;
    cout << "Test Case 1: " << (canAbhimanyuCross(enemies1, p1, a1, b1) ? "Pass" : "Fail") << endl;
    // test case 2
    vector<int> enemies2 = {10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
    int p2 = 150;
    int a2 = 3;
    int b2 = 2;
    cout << "Test Case 2: " << (canAbhimanyuCross(enemies2, p2, a2, b2) ? "Pass" : "Fail") << endl;

    return 0;
}