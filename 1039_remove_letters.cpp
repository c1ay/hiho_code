/*
Insert letter, calculator of removed letters
Input:3
    ABCBCCCAA
    AAA
    ABC
Output:9
    4
    2
*/

#include <iostream>  
#include <string.h>  
#define L 101  
  
using namespace std;  
  
int Deal(char word[]);  
int Find(char word[]);  
void insert(char arr[],int loc, char value);  
  
int main(void)  
{  
    int t;  
    char word[L];  
  
    for(cin>>t;t--;){  
        cin>>word;  
        cout<<Find(word)<<endl;  
    }  
    return 0;  
}  
  
  
int Deal(char word[]){  
    int count = 0;//消除总数  
    char result[L];  
    int i,j,c;  
    int flag = 1;  
    int len;  
    while(flag){  
        flag = 0;  
        c = i = 0;  
        len = strlen(word);  
        while(i<len){  
            for(j=i+1;j<len&&(word[j]==word[i]);j++){  
            }  
            if(j-i>1){//需要消去  
                count+= (j-i);  
                i = j;  
                flag = 1;  
            }else{  
                result[c++]=word[i++];  
            }  
        }  
        result[c] = '\0';  
        strcpy(word,result);  
    }  
    return count;  
}  
  
int Find(char word[]){  
    int count = 0;  
    int num = 3;  
    int len = strlen(word);  
    char temp[L];  
    for(int i=0;i<num;i++){  
        char c = 'A' + i;  
        int tempCount;  
        for(int j=0;j<=len;j++){  
            strcpy(temp,word);  
            insert(temp,j,c);  
            tempCount = Deal(temp);  
            if(count<tempCount){  
                count = tempCount;  
            }  
        }  
    }  
      
    return count;  
}  
  
void insert(char arr[],int loc, char value){  
    int len = strlen(arr);  
    int i = len;  
    arr[i+1] = '\0';  
    for(i;i>loc;i--){  
        arr[i] = arr[i-1];  
    }  
    arr[loc] = value;  
}  
