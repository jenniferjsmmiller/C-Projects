
#include <FPT.h>

// appropriate for a 600x600 window
double x[13] = {263,338,338,450,338,338,375,300,225,263,263,150,263} ;
double y[13] = {450,450,375,338,338,300,150,263,150,300,338,338,375} ;
int n = 13 ;


void translate (double dx, double dy)
{
  int i ;

  i = 0 ;
  while (i < n) {
    x[i] = x[i] + dx ;
    y[i] = y[i] + dy ;
    i = i + 1 ;
  }
}


void scale (double sx, double sy)
{
  int i ;

  i = 0 ;
  while (i < n) {
    x[i] = sx * x[i] ;
    y[i] = sy * y[i] ;
    i = i + 1 ;
  }
}


void rotate (double degrees)
{
  double radians,c,s,t ;
  int i ;

  radians = degrees*M_PI/180.0 ;
  c = cos(radians) ;
  s = sin(radians) ;

  i = 0 ;
  while (i < n) {
     t    = c*x[i] - s*y[i] ;
     y[i] = s*x[i] + c*y[i] ;
     x[i] = t ;
     i = i + 1 ;
  }
}



int main() 
{
 int j,q ;

 G_init_graphics(601, 601) ;

 j = 0 ;
 while (j < 200) {

   G_rgb(0,0,0) ;
   G_clear() ;
   G_rgb(0,0,1) ;
   G_fill_polygon(x,y,n) ;


   q = G_wait_key() ;
   // G_display_image() ; // use this to force display if not using G_wait_key
   // usleep(25000) ;  // microseconds 

   
   translate(-300, -300) ;
   scale(0.98, 0.98) ;
   rotate(3.0) ;
   translate(300, 300) ;

   j=j+1 ;
 }


 G_rgb(1,0,0) ;
 G_fill_circle(300,300,35) ;
 q = G_wait_key() ;
 while (q != 'q') {
   q = G_wait_key() ;
 }

}


