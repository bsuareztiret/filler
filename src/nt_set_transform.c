#include "../includes/filler_includes.h"

int   set_start(char *sstd, int i)
{
  if (sstd[i] == '0' && sstd[i + 1] == '0' && sstd[i + 2] == '0')
    return (1);
  return(0);
}

int   is_char_game(char c)
{
  if (c == '.' || c == 'X' || c == 'x' || c == 'O' || c == 'o')
    return (1);
  return (0);
}

char  *set_splitcpy(char *sstd, int i)
{
  char  *set;
  int   j;

  j = 0;
  if (!(set = ft_strnew(ft_strlen(sstd))))
    return (0);
  while (sstd[i] != 'P')
  {
    if (is_char_game(sstd[i]))
      set[j++] = sstd[i];
    i++;
  }
  return (0);
}
