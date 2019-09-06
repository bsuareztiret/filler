#include "../includes/filler_includes.h"

int   set_skip(char *sstd, int i)
{
  if (sstd[i] == '#' && sstd[i + 1] == ' ')
    return (1);
  return(0);
}

int   is_char_game(char c)
{
  if (c == '.' || c == 'X' || c == 'x' || c == 'O' || c == 'o' || c == '*')
    return (1);
  return (0);
}

int   is_char_piece(char c)
{
  if (c == '.' || c == '*')
    return (1);
  return (0);
}

void  set_splitcpy(char *sstd, char *set, int i)
{
  int   j;
  int   l;

  j = 0;
  l = 0;
  while (get_next_line(0, &sstd) > 0)
  while (sstd[i] != '\0')
  {
    if (set_skip(sstd, i))
      l++;
    if (is_char_game(sstd[i]) && l == 0)
      set[j++] = sstd[i];
    i++;
  }
 ft_printf("%s\n", set);
}
