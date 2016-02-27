//if n == 3, equilateral triangle
//if n == 4, quadrilateral
//if n == 5, pentagon
//if n > 2, inscribed shape corresponding to number of sides

#include <FPT.h>

int main() {
  double num_sides, angle, x_points[100], y_points[100], key_press;
  int i;

  cout << "How many sides would you like your polygon to have?: ";
  cin >> num_sides;

  G_init_graphics(600, 600);
  G_rgb(0, 0, 0);
  G_fill_circle(300, 300, 200);

  //while the increment hasn't hit the number of sides the user inputted, create points
  //based off of circle dimensions stated above
  i = 1;
  x_points[0] = 500;
  y_points[0] = 300;
  while (i < num_sides) {
    angle = i * (2 * M_PI/num_sides);
    x_points[i] = 300 + 200 * cos(angle);
    y_points[i] = 300 + 200 * sin(angle);
    i++;
  }
  
  //create shape based on the points created and the number of sides the user chose
  G_rgb(0, 0.5, 0.5);
  G_polygon(x_points, y_points, num_sides);

  key_press = G_wait_key();
}
    
