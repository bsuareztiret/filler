	#include "../includes/filler_includes.h"

  t_data    init_struct(void)
  {
		t_data	tmp;

    tmp.X = 0;
    tmp.Y = 0;
    tmp.plateauX = 0;
    tmp.plateauY = 0;
    tmp.piece = ft_strnew(60);
    return (tmp);
  }
