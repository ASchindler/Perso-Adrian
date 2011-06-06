#include <cstdio>
#include "incr_calc.h"

namespace soclib { namespace caba {

    // le constructeur 
	IncrCalc::IncrCalc(sc_core::sc_module_name insname,
			   int a30,
			   int a21,
			   int a12,
			   int a03,
			   int a20,
			   int a11,
			   int a02,
			   int a10,
			   int a01,
			   int a00):
	    sc_core::sc_module(insname)
	{
	    initialise_const(a30,
			     a21,
			     a12,
			     a03,
			     a20,
			     a11,
			     a02,
			     a10,
			     a01,
			     a00);
	    SC_THREAD(calc);
	    sensitive << clk.pos();
	}

	void IncrCalc::initialise_const(int a30,
			   int a21,
			   int a12,
			   int a03,
			   int a20,
			   int a11,
			   int a02,
			   int a10,
			   int a01,
			   int a00)
	{
	    a[9] = a30;
	    a[8] = a21;
	    a[7] = a12;
	    a[6] = a03;
	    a[5] = a20;
	    a[4] = a11;
	    a[3] = a02;
	    a[2] = a10;
	    a[1] = a01;
	    a[0] = a00;

	    b[5] = 3*a[9];
	    b[4] = 2*a[5];
	    b[3] = a[2];
	    b[2] = 3*a[9] + 2*a[8];
	    b[1] = a[5] + a[4];
	    b[0] = a[9] + a[8] + a[7];

	    c[2] = 6*a[9];
	    c[1] = 2*a[5];
	    c[0] = 6*a[9] + 2*a[8];
	    //sc_start(0, SC_NS);
	}

	void IncrCalc::calc()
	{
	    while(1)
	    {
		if(reset_n == false)
		    /*resets always to x=0, y=0*/
		{
		    cout << "RESET !!" << endl;
		    /*reinitialise line and column count to zero*/
		    lin = 0;
		    col = 0;

		    p0 = c[2];
		    
		    p1 = c[0];
		    p2 = b[0];
		    p3 = a[6];
		    
		    q0 = ((a[0])<< 2); //x_a03 * 6
		    /*q1_o = (x_a[0] << 2) + (x_a[0] << 1) + (x_a[1] << 1); //6*a03+2*a02
		    q2_o = x_a[0] + x_a[1] + x_a[3]; //a03 + a02 + a01
		    */
		    
		    r0 = a[2] << 1; //a12 * 2
		    //r1_o = x_a[2] + x_a[5] + x_a[4]; //a12 + a21 + a11
		    //r2_i = a[9] + a[8] + a[7]; //a30 + a20 + a10
		    
		    s0 = a[5] << 1; //a21 * 2
		    //s1_i = a[9] << 2 + a[9] << 1 + a[8] << 1; //a30*6 + a20*2
		    valid = 0;
		    wait_cyc = 1;
		    x_3 = 0;

		    /*pre_calculer la prochaine sortie*/
		    /*p3 = x_a[6] + x_b[0];
		    p2 = x_b[0] + x_c[0];
		    p1 = x_c[0] + x_c[2];*/
		    
		    // ne changent pas !!
		    q2 = a[0] + a[1] + a[3];
		    q1 = (a[0] << 2) + (a[0] << 1) + (a[1] << 1);
		    
		    r1 = a[2] + a[5] + a[4];


		    wait();
		}
		else
		{
		    if(wait_cyc.read())
		    {
			valid = 0;
			if(lin < TILE_HEIGHT)
			    wait_cyc = 0;
		    }
		    else
		    {
			valid = 1;
			/* move input to output 
			   p1_o = p1_i;
			   p2_o = p2_i;
			   p3_o = p3_i;

			   q2_o = q2_i;
			   q1_o = q1_i;
		    
			   r1_o = r1_i;
			   //valid = 1;*/

			/* save col 0 for next line, done at col 1 because then the output contains the previous value */
			if(col == 0)
			{
			    cout << "Saving coeffs ----- " << endl;
			    p3_l = p3;
			    p2_l = p2;
			    p1_l = p1;	
			}

			/* next column */
			if (col < TILE_WIDTH)
			{
			    if(col!=0)
			    {
				p3_l = p3_l;
				p2_l = p2_l;
				p1_l = p1_l;
			    }

			    col++;

			    /*
			      p3_i = p3_o + p2_o;
			      p2_i = p2_o + p1_o;
			      p1_i = p1_o + p0;
		    
			      q2_i = q2_o;
			      q1_i = q1_o;
			
			      r1_i = r1_o;
			    */

			    p3 = p3 + p2;
			    p2 = p2 + p1;
			    p1 = p1 + p0;
		    
			    q2 = q2;
			    q1 = q1;
			
			    r1 = r1;

			}
			else
			{	
			    
			    cout << "p3l " << p3_l << endl;
			    cout << "p2l " << p2_l << endl;
			    cout << "p1l " << p1_l << endl;
			
			    cout << "q0 " << q0 << endl;
			    cout << "q1 " << q1 << endl;
			    cout << "q2 " << q2 << endl;

			    cout << "r0 " << r0 << endl;
			    cout << "r1 " << r1 << endl;

			    cout << "s0 " << s0 << endl;
			    
		
			    col = 0;
			    valid = 0;

			    lin++;

			    p3 = p3_l + q2;

			    q2 = q2 + q1;
			    q1 = q1 + q0;

			    p2 = p2_l + r1;
			    r1 = r1 + r0;
			    p1 = p1_l + s0;
			    wait_cyc = 1;
			}
   		    
			x_3 = p3;
			x_2 = p2;
			x_1 = p1;

			cout << col << " " << lin << endl;
		    }
		    wait();
		}
	    }
	}
    }
}
