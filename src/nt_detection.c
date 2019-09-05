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

int   is_me(char *sstd, int i)
{
  if (sstd[i] == 'b' && sstd[i + 1] == 's' && sstd[i + 2] == 'u' &&
      sstd[i + 3] == 'a' && sstd[i + 4] == 'r' && sstd[i + 5] == 'e' &&
      sstd[i + 6] == 'z' && sstd[i + 7] == '-')
      return (1);
  return (0);
}

void  grep_player(char *sstd, t_data *tmp)
{
  get_next_line(0, &sstd);
  ft_printf("%s\n", sstd);
  if (ft_strstr(sstd, "p1"))
    tmp->player = 'O';
  if (ft_strstr(sstd, "p2"))
    tmp->player = 'X';
}

void  stock_info(char *sstd, t_data *tmp, int i, int j)
{
  char *nbr;
  int   l;
  int   k;

  nbr = ft_strnew(5);
  l = 0;
  k = 0;
  while (sstd[i] != '\n')
  {
    if (sstd[i] == ' ')
      i++;
    if (ft_isdigit(sstd[i]))
      nbr[l++] = sstd[i];
    if (sstd[i + 1] == ' ' || sstd[i + 1] == ':')
    {
      choose_axe(nbr, tmp, j);
      l = 0;
    }
    if (is_char_piece(sstd[i]))
    {
      tmp->piece[k++] = sstd[i];
    }
    i++;
  }
  ft_printf("****nbr :%d", nbr);

}

void  choose_axe(char *nbr, t_data *tmp, int j)
{
  if (j == 4 && tmp->Y == 0)
  {
    tmp->Y = atoi(nbr);
    ft_bzero(nbr, 5);
  }
  if (tmp->Y > 0 && j == 4)
  {
    tmp->X = atoi(nbr);
    ft_bzero(nbr, 5);
  }
  if (j == 6 && tmp->plateauY == 0)
  {
    tmp->plateauY = atoi(nbr);
    ft_bzero(nbr, 5);
  }
  if (tmp->plateauY > 0 && j == 6)
  {
    tmp->plateauX = atoi(nbr);
    ft_bzero(nbr, 5);
  }
}

void  grep_info(char *sstd, int i, t_data *tmp)
{
  int j;

  j = 0;
  i = -1;
  get_next_line(0, &sstd);
  ft_printf("%s\n", sstd);
  if (ft_strstr(sstd, "Plateau"))
    j = 6;
  ft_printf("j = %d\n", j);
  // if (ft_strstr(sstd, "Piece"))
  //   j = 4;
  if (j == 6 && ft_strstr(sstd, "15"))
    tmp->Y = 15;
  if (j == 6 && ft_strstr(sstd, "17"))
    tmp->X = 17;
  ft_printf("tmp.X = %d\n", tmp->X);
  ft_printf("tmp.Y = %d\n", tmp->Y);
  while (i <= tmp->Y)
  {
    get_next_line(0,&sstd);
    ft_printf("%s\n", sstd);
      i++;
  }

}
