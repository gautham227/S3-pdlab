#include <stdio.h>
#include <string.h>
#define LIMIT 10000

void toggle_move(char s[])
{
    int i;
    for(i=0;s[i];i++)  
    {
        if(s[i]>=65 && s[i]<=90)
         s[i]+=32;
        else if(s[i]>=97 && s[i]<=122)
         s[i]-=32;
    }
}


const char* merger_reverse_string(char str1[], char str2[])
{
  strcat(str1,str2);
  int n = strlen(str1);
  for (int i = 0; i < n / 2; i++)
  {
    char ch = str1[i];
    str1[i] = str1[n - i - 1];
    str1[n - i - 1] = ch;
  }
  printf("%s\n", str1);
}

int main()
{
  int p,i=0;
  char list[p][2][40];
  char a[10000], b[10000];
  scanf("%d", &p);
  for (i=0; i<p; i++)
  {
    scanf("%s", list[i][0]);
    scanf("%s", list[i][1]);
  }
    for (i=0; i<p; i++)
    {
    toggle_move(list[i][0]);
    toggle_move(list[i][1]);
    merger_reverse_string(list[i][0],list[i][1]);
    }
  return 0;
}