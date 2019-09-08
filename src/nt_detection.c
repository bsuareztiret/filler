#include "../includes/filler_includes.h"

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
  if (tmp->X && tmp->Y)
  {
    if (ft_strstr(sstd, ".") || ft_strstr(sstd, "*"))
      tmp->piece = ft_strcat(tmp->piece, sstd);
  }
  else if (ft_strstr(sstd, "x") || ft_strstr(sstd, "X") ||
      ft_strstr(sstd, "o") || ft_strstr(sstd, "O") ||
      ft_strstr(sstd, "."))
  {
    cp = ft_strsplit(sstd, ' ');
    tmp->set = ft_strcat(tmp->set, cp[1]);
  }
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
    nbr = ft_strsplit(sstd, ' ')[2];
    tmp->plateauX = ft_atoi(nbr);
  }
}

void  grep_info(char *sstd, t_data *tmp)
{
  get_next_line(0, &sstd);
  if (ft_strstr(sstd, "Plateau"))
    choose_axe(sstd, tmp, 6);
  if (ft_strstr(sstd, "Piece"))
    choose_axe(sstd, tmp, 4);
  if (ft_strstr(sstd, " ") || ft_strstr(sstd, "*") || ft_strstr(sstd, "."))
    stock_info(sstd, tmp);
  // ft_printf("tmp.X = %d\n", tmp->X);
  // ft_printf("tmp.Y = %d\n", tmp->Y);
  // ft_printf("tmp.pppX = %d\n", tmp->plateauX);
  // ft_printf("tmp.pppY = %d\n", tmp->plateauY);
  // ft_printf("tmp.set: %s\n", tmp->set);
  // ft_printf("tmp.piece: %s\n", tmp->piece);
}
