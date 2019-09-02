#include "../includes/filler_includes.h"

int   is_p(char* sstd, int i)
{
  int j;

  j = 0;
  if (sstd[i + 1] == 'l' && sstd[i + 2] == 'a' && sstd[i + 3] == 't')
    j++;
  if (sstd[i + 4] == 'e' && sstd[i + 5] == 'a' && sstd[i + 6] == 'u')
    j--;
  if (sstd[i + 1] == 'i' && sstd[i + 2] == 'e' && sstd[i + 3] == 'c')
    j++;
  if (sstd[i + 1] == 'e')
    j++;
  return (j);
}

int  *axe_info(char *sstd, int i)
{
  /*
    FAIT UNE STRUCTURE pour stocker les infos des pieces,
    un INT pour la taille, et un CHAR.
  */
}

char  *stock_piece(char *sstd, int i)
{
  /*
    FAIT UNE STRUCTURE pour stocker les infos des pieces,
    un INT pour la taille, et un CHAR.
  */
}
