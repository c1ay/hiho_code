#include <iostream>

/*multi line plus
Input: 1 2
       3 4
Output:3
       7
*/

using namespace std;

int main(void) {
    int a, b;
    while(cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}

