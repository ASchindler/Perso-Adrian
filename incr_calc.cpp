#include <cstdio>
#include "incr_calc.h"

namespace soclib { namespace caba {

    // le constructeur 
	IncrCalc::IncrCalc(sc_core::sc_module_name insname):
	    sc_core::sc_module(insname)
	{
	    SC_THREAD(x_calc);
	    sensitive << clk.pos();
	    SC_THREAD(y_calc);
	    sensitive << clk.pos();
	}

	void IncrCalc::initialise_const()
	{
	    x_a[9] = 2;
	    x_a[8] = -3;
	    x_a[7] = 2;
	    x_a[6] = 0;
	    x_a[5] = 0;
	    x_a[4] = -2;
	    x_a[3] = 1;
	    x_a[2] = 2;
	    x_a[1] = -1;
	    x_a[0] = 0;

	    x_b[5] = 3*x_a[9];
	    x_b[4] = 2*x_a[5];
	    x_b[3] = x_a[2];
	    x_b[2] = 3*x_a[9] + 2*x_a[8];
	    x_b[1] = x_a[5] + x_a[4];
	    x_b[0] = x_a[9] + x_a[8] + x_a[7];

	    x_c[2] = 6*x_a[9];
	    x_c[1] = 2*x_a[5];
	    x_c[0] = 6*x_a[9] + 2*x_a[8];
	}

	void IncrCalc::x_calc()
	{
	    while(1)
	    {
		if(reset_n == false)
		    /*resets always to x=0, y=0*/
		{
		    /*reinitialise line and column count to zero*/
		    initialise_const();
		    lin = 0;
		    col = 0;

		    p0 = x_c[2];
		    p1_i = x_c[0];
		    p2_i = x_b[0];
		    p3_i = x_a[6];
		    
		    q0 = ((x_a[0])<< 2);// + (x_a[0]) << 1; //x_a03 * 6
		    q1_i = x_a[0] << 2 + x_a[0] << 1 + x_a[1] << 1; //a03 * 6 + 2 * a02
		    q2_i = x_a[0] + x_a[1] + x_a[3]; //a03 + a02 + a01
		    //q3_i = a[6]; //a00
		    
		    r0 = x_a[2] << 1; //a12 * 2
		    r1_i = x_a[2] + x_a[5] + x_a[4]; //a12 + a21 + a11
		    //r2_i = a[9] + a[8] + a[7]; //a30 + a20 + a10
		    
		    s0 = x_a[5] << 1; //a21 * 2
		    //s1_i = a[9] << 2 + a[9] << 1 + a[8] << 1; //a30*6 + a20*2
		    valid = 0;
		    x_3 = 0;

		    wait();
		}
		else
		{
		    /* move input to output */
		    p1_o = p1_i;
		    p2_o = p2_i;
		    p3_o = p3_i;

		    q2_o = q2_i;
		    q1_o = q1_i;
		    
		    r1_o = r1_i;

		    /* save col 0 for next line */
		    if(col == 0)
		    {
			p3_l = p3_o;
			p2_l = p2_o;
			p1_l = p1_o;			
		    }

		    /* next column */
		    if (col < 640)
		    {
			col++;

			p3_i = p3_o + p2_o;
			p2_i = p2_o + p1_o;
			p1_i = p1_o + p0;
		    
			q2_i = q2_o;
			q1_i = q1_o;
			
			r1_i = r1_o;
		    }
		    else
		    {			
			col = 0;

			lin++;

			p3_i = p3_l + q2_o;

			q2_i = q2_o + q1_o;
			q1_i = q1_o + q0;

			p2_i = p2_l + r1_o;
			r1_i = r1_o + r0;
			p1_i = p1_l + s0;
		    }
   		    
		    valid = 1;
		    x_3 = p3_o;
		    x_2 = p2_o;
		    x_1 = p1_o;

		    wait();
		}
	    }
	}

	void IncrCalc::y_calc()
	{
	    while(1)
	    {
		if(reset_n == false)
		{
		    wait();
		}
		else
		{
		    wait();
		}
	    }
	}
    }
}
