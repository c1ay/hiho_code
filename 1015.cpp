#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int ViolentMath(char* s, char* p);

int main(){
    int  n;
    cin >> n;
    int words[n];
    char p[10000];
    char s[1000000];
    for(int i = 0;i < (n * 2); i++){
        if (i % 2){
            cin >> s;
            words[(i - 1)/2] = ViolentMath(s, p);
        }else{
            cin >> p;
        }
    }
    for(int i = 0; i < n; i++){
        cout << words[i] << endl;
    }
    return 0;
}

int ViolentMath(char* s, char *p){
    int sLen = strlen(s);
    int pLen = strlen(p);
    int matchCount = 0;

    int i = 0;
    int j = 0;
    while (i <= sLen ){
        if (s[i] == p[j]){
            if (j == pLen -1){
                matchCount++;
                i = i - j + 1;
                j = 0;
            }else{
                i++;
                j++;
            }
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    return matchCount;
}
