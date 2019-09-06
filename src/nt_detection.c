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
  // ft_bzero(sstd, 60000);
}

void  stock_info(char *sstd, t_data *tmp)
{
  char  **cp;

  cp = NULL;
  while (sstd[j] != '\0')
  {
    if (is_char_game(sstd[i])

  }
  tmp->set = cp[1];
  // tmp->set[tmp->i] = cp[1];
  ft_printf("cp = %s\n", cp[1]);

  // ft_printf("tmp->set = %s\n", tmp->set);
  // char *nbr;
  // int   l;
  // int   k;
  //
  // nbr = ft_strnew(5);
  // l = 0;
  // k = 0;
  // while (sstd[i] != '\n')
  // {
  //   if (sstd[i] == ' ')
  //     i++;
  //   if (ft_isdigit(sstd[i]))
  //     nbr[l++] = sstd[i];
  //   if (sstd[i + 1] == ' ' || sstd[i + 1] == ':')
  //   {
  //     choose_axe(nbr, tmp, j);
  //     l = 0;
  //   }
  //   if (is_char_piece(sstd[i]))
  //   {
  //     tmp->piece[k++] = sstd[i];
  //   }
  //   i++;
  // }
  // ft_printf("****nbr :%d", nbr);
}

void  choose_axe(char *sstd, t_data *tmp, int j)
{
  char *nbr;

  nbr = NULL;
  if (j == 4)
  {
    nbr = ft_strsplit(sstd, ' ')[1];
    tmp->Y = ft_atoi(nbr);
    nbr = ft_strsplit(sstd, ' ')[2];
    tmp->X = ft_atoi(nbr);
  }
  if (j == 6)
  {
    nbr = ft_strsplit(sstd, ' ')[1];
    tmp->plateauY = ft_atoi(nbr);
    // ft_printf("nbr = %s\n", nbr);
    // ft_printf("plateauY = %d\n", tmp->plateauY);
    nbr = ft_strsplit(sstd, ' ')[2];
    tmp->plateauX = ft_atoi(nbr);
    // ft_printf("/nbr = %s\n", nbr);
    // ft_printf("/plateauX = %d\n", tmp->plateauX);
  }
}

void  grep_info(char *sstd, int i, t_data *tmp)
{
  int j;

  j = 0;
  i = 0;
  get_next_line(0, &sstd);
  // ft_printf("%s\n", sstd);
  // if (ft_strstr(sstd, "Plateau"))
  //   j = 6;
  // if (ft_strstr(sstd, "Piece"))
  //   j = 4;
  ft_printf("j = %d\n", j);

  if (ft_strstr(sstd, "Plateau"))
    choose_axe(sstd, tmp, 6);
  if (ft_strstr(sstd, "Piece"))
    choose_axe(sstd, tmp, 4);
  ft_printf("tmp.X = %d\n", tmp->X);
  ft_printf("tmp.Y = %d\n", tmp->Y);
  ft_printf("tmp.pppX = %d\n", tmp->plateauX);
  ft_printf("tmp.pppY = %d\n", tmp->plateauY);
  if (ft_strstr(sstd, " "))
    stock_info(sstd, tmp);
  // ft_printf("tmp.set = %s\n", tmp->set);
}
