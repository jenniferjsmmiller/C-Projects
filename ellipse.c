#include <FPT.h>

int main() {
  
  double x_coordinate, y_coordinate, angle, radius,
   bot_x_points[1000], bot_y_points[1000], top_x_points[1000], top_y_points[1000];
  int i, j, k, key_press, adjustment;

  G_init_graphics(600, 600);

  //create point set for bottom ellipse based off of equation of ellipse
  angle = 0;
  x_coordinate = 300;
  y_coordinate = 100;
  radius = 125;
  i = 0;
  while (angle <= 360) {
    bot_x_points[i] = x_coordinate + radius * cos(angle * M_PI/180);
    bot_y_points[i] = y_coordinate - 0.5 * radius * sin(angle * M_PI/180);
    G_point(bot_x_points[i], bot_y_points[i]);
    angle += 7;
    i++;
  }
  G_polygon(bot_x_points, bot_y_points, i);

  //create point set for top ellipse based off of equation of ellipse
  angle = 0;
  x_coordinate = 300;
  y_coordinate = 500;
  radius = 125;
  i = 0;
  while (angle <= 360) {
    top_x_points[i] = x_coordinate + radius * cos(angle * M_PI/180);
    top_y_points[i] = y_coordinate - 0.5 * radius * sin(angle * M_PI/180);
    G_point(top_x_points[i], top_y_points[i]);
    angle += 7;
    i++;
  }
  G_polygon(top_x_points, top_y_points, i);

  //create moving ellipse, where the adjustment allows for the ellipse to move freely without bugs
  j = 0;
  k = 0;
  adjustment = 0;
  while (j < i) {
    G_rgb(0, 0, 0);
    G_line(bot_x_points[j], bot_y_points[j],
     top_x_points[(k + adjustment) % i], top_y_points[(k + adjustment) % i]);
    G_polygon(bot_x_points, bot_y_points, i);
    G_polygon(top_x_points, top_y_points, i);
    j++;
    k++;
    while (j == i) {
      j = 0;
      k = 0;
      adjustment++;
      G_wait_key();
      G_rgb(1, 1, 1);
      G_clear();
    }
  }

  key_press = G_wait_key();
}
