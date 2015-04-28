#include <FPT.h>

int main()

{
  double h, k, angle, radius, x[1000], y[1000], a[1000], b[1000] ;
  int i, q, t, u, j ;

  G_init_graphics(600, 600) ;

  angle=0 ;
  h=300 ;
  k=100 ;
  radius=125 ;
  i=0 ;
  while (angle <= 360){
    x[i]=h + radius*cos(angle*M_PI/180) ;
    y[i]=k-0.5*radius*sin(angle*M_PI/180) ;
    G_point(x[i], y[i]) ;
    angle=angle+7 ;
    i++ ;
  }
  G_polygon(x, y, i) ;

  angle=0 ;
  h=300 ;
  k=500 ;
  radius=125 ;
  i=0 ;
  while (angle <= 360){
    a[i]=h + radius*cos(angle*M_PI/180) ;
    b[i]=k-0.5*radius*sin(angle*M_PI/180) ;
    G_point(a[i], b[i]) ;
    angle=angle+7 ;
    i++ ;
  }
  G_polygon(a, b, i) ;

  t=0 ;
  u=0 ;
  j=0 ;
  while (t < i){
    G_rgb(0, 0, 0) ;
    G_line(x[t], y[t], a[(u+j)%i], b[(u+j)%i]) ;
    G_polygon(x, y, i) ;
    G_polygon(a, b, i) ;
    t++ ;
    u++ ;
    while (t==i){
      t=0 ;
      u=0 ;
      j++ ;
      G_wait_key() ;
      G_rgb(1, 1, 1) ;
      G_clear() ;
    }
  }


  q=G_wait_key() ;
}
