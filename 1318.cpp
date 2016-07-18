#include <iostream>
#include <cmath>

using namespace std;

const int mod = 1000000007;

int main(){
    int bitLen;
    cin >> bitLen;
    long long  ret[101];
    ret[0] = ret[1] = 0;
    ret[2] = 1;
    ret[3] = 3;
    for (int i=3; i <= bitLen; i++){
        int tmp = pow(2, (i - 2));
        ret[i] = ret[i-1] + ret[i-2] + tmp;
    }
    cout << ret[bitLen] % mod << endl;
    return 0;
}
