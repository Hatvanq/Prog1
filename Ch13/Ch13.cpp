/*
    g++ Ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
using namespace Graph_lib;

	int xmax = 800;
    int ymax = 1000;

Simple_window win {Point{100,100}, xmax, ymax, "Drill 13"};

	int x_grid = 100;
    int y_grid = 100;

Lines grid;

    for (int x=x_grid; x<xmax; x+=x_grid)
    	grid.add(Point{x,0},Point{x,ymax});
    for (int y=y_grid; y<ymax; y+=y_grid)
    	grid.add(Point{0,y},Point{xmax,y});
   
Rectangle r1 {Point{0,0}, 100, 100};
Rectangle r2 {Point{100,100}, 100, 100};
Rectangle r3 {Point{200,200}, 100, 100};
Rectangle r4 {Point{300,300}, 100, 100};
Rectangle r5 {Point{400,400}, 100, 100};
Rectangle r6 {Point{500,500}, 100, 100};
Rectangle r7 {Point{600,600}, 100, 100};
Rectangle r8 {Point{700,700}, 100, 100};

	r1.set_fill_color(Color::red);
	r2.set_fill_color(Color::red);
	r3.set_fill_color(Color::red);
	r4.set_fill_color(Color::red);
	r5.set_fill_color(Color::red);
	r6.set_fill_color(Color::red);
	r7.set_fill_color(Color::red);
	r8.set_fill_color(Color::red);

Image i {Point{0,400}, "200.jpg"};
Image ii {Point{200,400}, "200.jpg"};
Image iii {Point{600,400}, "200.jpg"};

Image k {Point{0,0}, "100.jpg"};

win.attach(grid);
win.attach(r1);
win.attach(r2);
win.attach(r3);
win.attach(r4);
win.attach(r5);
win.attach(r6);
win.attach(r7);
win.attach(r8);
win.attach(i);
win.attach(ii);
win.attach(iii);
win.attach(k);

for(int i = 0; i < 8; ++i)
    {
    	for(int j = 0; j < 8; j++)
    	{
    		win.wait_for_button();
    		if(j < 7) k.move(100, 0);
    		else k.move(-700, 100);
    	}

    }

}