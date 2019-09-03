	#include "../includes/filler_includes.h"

  t_data    init_struct(void)
  {
		t_data	tmp;

    tmp.X = 0;
    tmp.Y = 0;
    tmp.plateauX = -1;
    tmp.plateauY = -1;
    tmp.piece = ft_strnew(60);
    return (tmp);
  }
