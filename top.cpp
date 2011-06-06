#include "systemc.h"
#include "incr_calc.h"
#include <cmath>

void next_cycle (sc_signal<bool> &signal_clk);

int sc_main(int argc, char *argv[])
{
    using namespace sc_core;
    using namespace soclib::caba;    

    int i;
    int x, y;
    char x_exp;

    int a30 = 2;
    int a20 = -3;
    int a10 = 2;
    int a00 = 0;
    int a21 = 0;
    int a11 = -2;
    int a01 = 1;
    int a12 = 2;
    int a02 = -1;
    int a03 = 0;

    sc_signal<bool> clk;
    sc_signal<bool> reset_n;
    sc_signal<char> x_3;
    sc_signal<char> x_2;
    sc_signal<char> x_1;
    sc_signal<bool> x_valid;

    sc_trace_file *my_trace_file;
    my_trace_file =
        sc_create_vcd_trace_file ("incr_calc_trace");
    sc_trace(my_trace_file, clk, "clk");
    sc_trace(my_trace_file, reset_n, "reset");
    sc_trace(my_trace_file, x_3, "x_3");
    sc_trace(my_trace_file, x_2, "x_2");
    sc_trace(my_trace_file, x_1, "x_1");
    sc_trace(my_trace_file, valid, "valid");

    IncrCalc my_calc("coproc_incr", a30, a20, a10, a00, a21, a11, a01, a12, a02, a03);
    my_calc.clk(clk);
    my_calc.reset_n(reset_n);
    my_calc.x_3(x_3);
    my_calc.x_2(x_2);
    my_calc.x_1(x_1);

    my_calc.valid(x_valid);

    next_cycle(clk);
    next_cycle(clk);
    reset_n = true;
    next_cycle(clk);
    next_cycle(clk);
    next_cycle(clk);
    reset_n = false;
    next_cycle(clk);
    next_cycle(clk);
    next_cycle(clk);
    reset_n = true;

    x = 0;
    y = 0;
    x_exp = 0;

    for(i=0; i<(640*550); i++)
    //while(i<640*550)//for(i=0; i<(640*482); i++)
    {
	if(valid.read())
	{
	    if (x == 640)
	    {
		x = 0;
		y++;
		cout << endl << "Line " << y << endl;
	    }
	   
	    x_exp = a30 * pow(x,3) + a21 * pow(x,2) * y + a12 * x * pow(y,2) + a03 * pow(y,3) + a20 * pow(x,2) + a11 * x * y + a02 * pow(y,2) + a10 * x + a01 * y + a00;
	    if (x_exp != x_3.read())
	    {
		cout << "error !! expected: " << (int)x_exp << " actual: " << (int)x_3 << endl;
		exit(1);
	    }
	    cout << (int)x_exp << endl;
	    x++;
	}
        next_cycle(clk);
    }

    sc_close_vcd_trace_file (my_trace_file);

    return EXIT_SUCCESS;

}

void next_cycle (sc_signal<bool> &signal_clk)
{
    signal_clk = false;
    sc_start (1, SC_NS);
    signal_clk = true;
    sc_start (1, SC_NS);
}



			
			
