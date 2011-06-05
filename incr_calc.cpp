#include <cstdio>
#include "incr_calc.h"

namespace soclib { namespace caba {

    // le constructeur 
	IncrCalc::IncrCalc()
	{
	    SC_THREAD(line_calc);
	    sensitive << clk.pos();
	    SC_THREAD(col_calc);
	    sensitive << clk.pos();
	}

	void VideoGen::x_calc()
	{
	    while(1)
	    {
		if(reset_n == false)
		    /*resets always to x=0, y=0*/
		{
		    /*reinitialise line and column count to zero*/
		    lin = 0;
		    col = 0;

		    p0 = c[2];
		    p1_i = c[0];
		    p2_i = b[0];
		    p3_i = a[6];
		    
		    q0 = a[0] << 2 + a[0] << 1; //a03 * 6
		    q1_i = a[0] << 2 + a[0] << 1 + a[1] << 1; //a03 * 6 + 2 * a02
		    q2_i = a[0] + a[1] + a[3]; //a03 + a02 + a01
		    //q3_i = a[6]; //a00
		    
		    r0 = a[2] << 1; //a12 * 2
		    r1_i = a[2] + a[5] + a[4]; //a12 + a21 + a11
		    //r2_i = a[9] + a[8] + a[7]; //a30 + a20 + a10
		    
		    s0 = a[5] << 1; //a21 * 2
		    //s1_i = a[9] << 2 + a[9] << 1 + a[8] << 1; //a30*6 + a20*2
		    valid = 0;

		    wait();
		}
		else
		{
		    /* move input to output */
		    p0_o = p0_i;
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
		    if (col << 640)
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
		    x_o = p3_o;

		    wait();
		}
	    }
	}

	void VideoGen::y_calc()
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
