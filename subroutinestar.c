#include <FPT.h>

int star(int circle_center_x, int circle_center_y, int radius) {
  int i;
  double x_points[10], y_points[10];

  G_circle (circle_center_x, circle_center_y, radius);
  i = 0;
  while (i < 5) {
    x_points[i] = circle_center_x + radius * cos((M_PI/2) + i * (4 * M_PI/5));
    y_points[i] = circle_center_y + radius * sin((M_PI/2) + i * (4 * M_PI/5));
    i++;
  }

  i = 0;
  while (i < 3) {
    G_fill_triangle (circle_center_x, circle_center_y, x_points[i], 
      y_points[i], x_points[i + 1], y_points[i + 1]) ;
    i++;
  }
  return G_fill_polygon(x_points, y_points, 5);
}

int main() {
  G_init_graphics(600, 600);
  G_rgb(0, 0.5, 0.5);
  star(300, 400, 75);
  G_wait_key();
}
