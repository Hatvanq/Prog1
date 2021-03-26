/*
    g++ Ch15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double x) { return 1; }

double slope(double x) { return x/2; }

double square(double x) { return x*x; }

double sloping_cos(double x ) { return slope(x) + cos(x); }

int main()
{

using namespace Graph_lib;

int xmax = 600;
int ymax = 600;

	Simple_window win(Point{100,100}, xmax, ymax, "Function graphs");

	Axis x {Axis::x, Point{100,300}, 400, 20, "1 = = 20 pixels"};
	Axis y {Axis::y, Point{300,500}, 400, 20, "1 = = 20 pixels"};

    x.set_color(Color::red);
    y.set_color(Color::red);

int rangemin = -10;
int rangemax = 11;
int numberpoints = 400;
int xscale = 20;
int yscale = 20;
int xorig = xmax / 2;
int yorig = ymax / 2;

	Point orig {xorig, yorig};

	Function oneline(one, rangemin, rangemax, orig, numberpoints, xscale, yscale);

	Function slopeline(slope, rangemin, rangemax, orig, numberpoints, xscale, yscale);

	Text text{ Point{100,390}, "x/2" };

	Function squareline(square, rangemin, rangemax, orig, numberpoints, xscale, yscale);

	Function cosline(cos, rangemin, rangemax, orig, numberpoints, xscale, yscale);
	cosline.set_color(Color::blue);

	Function slopingcosline(sloping_cos, rangemin, rangemax, orig, numberpoints, xscale, yscale);

win.attach(x);
win.attach(y);
win.attach(oneline);
win.attach(slopeline);
win.attach(text);
win.attach(squareline);
win.attach(cosline);
win.attach(slopingcosline);

win.wait_for_button();

return 0;
}