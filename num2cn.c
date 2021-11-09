#include "stdio.h"
#include "math.h"
#include "string.h"

char *number_string[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
char *unit_string[] = {"十", "百", "千", "万"};

/*字符串拼接*/
char *my_strcat(char *str1, char *str2)
{
  char *pt = str1;
  while (*str1 != '\0')
    str1++;
  while (*str2 != '\0')
    *str1++ = *str2++;
  *str1 = '\0';
  return pt;
}

/*确定数组的位数*/
char number_of_digits(int x)
{
  char count = 0;
  if (x == 0)
    count = 0;
  else
  {
    while (x)
    {
      x = x / 10;
      count++;
    }
  }
  return count;
}

/*数字与汉字的转换*/
char num2chinese(int x, char *str)
{
  int i, j, k;
  char s[33] = {0};
  j = number_of_digits(x);
  if (j == 0)
    my_strcat(s, number_string[0]);
  for (j; j > 0; j--)
  {
    i = pow(10, j - 1);
    k = (x / i) % 10;
    if (k != 0)
    {
      my_strcat(s, number_string[k]);
      if (j != 1)
        my_strcat(s, unit_string[j - 2]);
    }
  }
  my_strcat(str, s);
  return 0;
}
