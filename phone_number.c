#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_possible_strings(const char*, int, char*);
char *arr[9] = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
};

int main(void) {
   char res[64];
   memset(res, 0, sizeof(res));
   print_possible_strings("22456", 0, res);
}

void print_possible_strings(const char *str, int index, char *res) {
   if(strlen(str) == index) {
      printf("%s\n", res);
   } else {
      int i = 0;
      int offset = str[index] - '0';
      int len = strlen(arr[offset]);
      for(i = 0; i < len; i++) {
         res[index] = arr[offset][i];
         print_possible_strings(str, index+1, res);
      }
   }
}


