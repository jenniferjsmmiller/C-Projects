#include <FPT.h>

int star(int xx, int yy, int radius)

{
  int i, t ;
  double x[10], y[10] ;
  G_circle (xx, yy, radius) ;
  i=0 ;
  while (i < 5){
    x[i]=xx+radius*cos((M_PI/2)+i*(4*M_PI/5)) ;
    y[i]=yy+radius*sin((M_PI/2)+i*(4*M_PI/5)) ;
    i++ ;
  }
  i=0 ;
  while (i < 3){
    G_fill_triangle(xx, yy, x[i], y[i], x[i+1], y[i+1]) ;
    i++ ;
  }

  return G_fill_polygon(x, y, 5) ;
}

int main()

{
  G_init_graphics(600, 600) ;

  G_rgb(0, 0.5, 0.5) ;
  star(300, 400, 75) ;

  G_wait_key() ;
}
