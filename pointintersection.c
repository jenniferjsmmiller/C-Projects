#include <FPT.h>

int main() {

  double p[2], x, y, a, b, dist;
  G_init_graphics(600, 600);
  G_fill_circle(300, 300, 2);
  G_circle(300, 300, 200);
  G_wait_click(p);
  G_line(300, 300, p[0], p[1]);
  G_fill_circle(p[0], p[1], 2);

  x = p[0] - 300;
  y = p[1] - 300;
  dist = sqrt(x*x + y*y);
  a = (200/dist) * x;
  b = (200/dist) * y;
  G_fill_circle(300 + a, 300 + b, 2);
  //circles intersection

  G_line(300 + a, 300 + b, 300 + a - b, 300 + a + b);
  G_fill_circle(300 + a - b, 300 + a + b, 2);
  //perpendicular line
  G_line(300+0.75*a, 300+0.75*b, 300+0.75*a-b, 300+0.75*a+b);
  G_fill_circle(300+0.75*a-b, 300+0.75*a+b, 2);
  G_line(300+0.25*a, 300+0.25*b, 300+0.25*a-0.3*b, 300+0.25*a+0.3*b);


  G_wait_key();

  

}
