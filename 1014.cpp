#include <iostream>
#include <stdio.h>
using namespace std;
 
struct Tire{
     int num;     Tire* next[26];
     Tire()
     {
         num=0;
         int i;
         for(i=0;i<26;i++)
             next[i] = NULL;
     }
}tree;
 
void Insert(char word[])
{
    Tire* p = &tree;
    int i;
    for(i=0;word[i];i++){
         int t = word[i]-'a';
        if(p->next[t]==NULL)
             p->next[t] = new Tire;
        p = p->next[t];
        p->num++;
     }
 }
 
 int Find(char word[])
 {
    Tire* p = &tree;
     int i;
     for(i=0;word[i];i++){
        int t = word[i]-'a';
        if(p->next[t]==NULL)
             return 0;
        p = p->next[t];
     }
     return p->num;
 }
 
 int main()
 {
     int n;
    char word[11];
     //字典
     scanf("%d",&n);
     gets(word);
     while(n--){    //读取单词  n次
         gets(word);    
         Insert(word);    //将单词插入到字典树中
    }
    //询问
     scanf("%d",&n);
     gets(word);    //将回车读入
     while(n--){
         gets(word);
        printf("%d\n",Find(word));    //查询以word为前缀的单词出现过几次
     }
    return 0;
}
