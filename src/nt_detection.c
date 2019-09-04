#include "../includes/filler_includes.h"

int   is_p(char* sstd, int i)
{
  int j;

  j = 0;
  if (sstd[i + 1] == 'l' && sstd[i + 2] == 'a' && sstd[i + 3] == 't')
    j += 3;
  if (sstd[i + 4] == 'e' && sstd[i + 5] == 'a' && sstd[i + 6] == 'u')
    j += 3;
  if (sstd[i + 1] == 'i' && sstd[i + 2] == 'e' && sstd[i + 3] == 'c')
    j += 3;
  return (j);
}

void  stock_info(char *sstd, t_data *tmp, int i, int j)
{
  char *nbr;
  int   l;

  nbr = ft_strnew(5);
  l = 0;
  while (sstd[i] != ':')
  {
    if (sstd[i] == ' ' && l == 0)
      i++;
    if (ft_isdigit(sstd[i]))
      nbr[l++] = sstd[i];
    ft_printf("%s\n", nbr);
    if (l == 2)
    {
      choose_axe(nbr, tmp, j);
      l = 0;
    }
    i++;
  }
}

void  choose_axe(char *nbr, t_data *tmp, int j)
{
  ft_printf("----------%d---------\n", j);
  ft_printf("------tmp:%d---------\n", tmp->plateauY);

  if (j == 3 && tmp->Y == -1)
  {
    tmp->Y = atoi(nbr);
    ft_bzero(nbr, 3);
  }
  if (tmp->Y > 0 && j == 3)
  {
    tmp->X = atoi(nbr);
    ft_bzero(nbr, 3);
  }
  if (j == 6 && tmp->plateauY == -1)
  {
    tmp->plateauY = atoi(nbr);
    ft_bzero(nbr, 3);
  }
  if (tmp->plateauY > 0 && j == 6)
  {
    tmp->plateauX = atoi(nbr);
    ft_bzero(nbr, 3);
  }
  ft_printf("tmp->X = %d\ntmp->Y = %d\ntmp->plateauX = %d\ntmp->plateauY = %d\n", tmp->X, tmp->Y, tmp->plateauX, tmp->plateauY);

}

void  grep_info(char *sstd, int i, t_data *tmp)
{
  int j;

  j = 0;
  while (sstd[i] != '\0')
  {
    if (sstd[i] == 'P')
      j = is_p(sstd, i);
    if (j == 6 || j == 3)
      stock_info(sstd, tmp, i, j);
    j = 0;
    i++;
  }
  //ft_printf("tmp.X = %d\ntmp.Y = %d\ntmp.plateauX = %d\ntmp.plateauY = %d\n", tmp.X, tmp.Y, tmp.plateauX, tmp.plateauY);
}
