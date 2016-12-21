#include "stdio.h"

int calculateResult(unsigned l,unsigned r, int k);
int* getNumbers(unsigned number, int numbers[], int* numLen);
int calculateAlternatingSum(int* numbers, int numLen);
const int MOD = 1000000007;

int main(){
  // handle input and output
  unsigned startNum=0, endNum=0;
  int k;
  scanf("%u", &startNum);
  scanf("%u", &endNum);
  scanf("%d", &k);
  unsigned ret = calculateResult(startNum, endNum, k);
  // printf("main ret: %d", ret);
  printf("%d\n", ret%MOD);
  return 0;
}

int calculateResult(unsigned l, unsigned r, int k){
  /*
    calculate alternating sum
  */
  unsigned ret = 0;
  unsigned start;
  for(start=l; start<=r; start++){
    int numbers[100000];
    int numLen = 0;
    getNumbers(start, numbers, &numLen);
    if (k == calculateAlternatingSum(numbers, numLen)){
      ret += start;
      printf("%u, %u\n", start, ret);
    }
  }
  printf("ret: %u\n", ret);
  return ret;
}

int* getNumbers(unsigned number, int numbers[], int* numLen){
  /*
    get single bit of the number
  */
  // int index = 0;
  for (; number > 0;){
    numbers[*numLen++] = number % 10;
    number /= 10;
  }
  // numbers[++index] = -1;
  printf("num: %d\n", *numLen);
  return numbers;
}

int calculateAlternatingSum(int* numbers, int numLen){
  int alternatingSum = 0;
  int index=0;
  for (;index<numLen;index++){
    // if (numbers[index]=-1) break;
    if (index%2){
      alternatingSum += numbers[index];
    } else{
      alternatingSum -= numbers[index];
    }
  }
  printf("len: %d\n", numLen);
  printf("cal: %d\n", alternatingSum);
  return alternatingSum;
}
