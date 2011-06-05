#include <systemc>
#include "mfixed.h"

using namespace sc_core;
using namespace std;

namespace soclib { namespace caba {

    class IncrCalc
        :sc_module {

	private:
	    /*private line and column counter*/
	    int lin;
	    int col;

            public:
                // IO PORTS

                sc_in_clk           clk;
                sc_in<bool>         reset_n;
		
                mfixed  x_a[10];
                mfixed  y_a[10];
		/*
		  a[9] - a30
		  a[8] - a20
		  a[7] - a10
		  a[6] - a00
		  a[5] - a21
		  a[4] - a11
		  a[3] - a01
		  a[2] - a12
		  a[1] - a02
		  a[0] - a03
		 */

		mfixed  x_b[6];
		/*
		  b[5] - b20
		  b[4] - b11
		  b[3] - b10
		  b[2] - b02
		  b[1] - b01
		  b[0] - b00
		*/
		mfixed  y_b[6];

		mfixed  x_c[3];
		/*
		  c[2] - c10
		  c[1] - c01
		  c[0] - c00	
		*/
		mfixed  y_c[3];

		/* registres */

		mfixed q0;  //constante	
		mfixed q1_i;
		mfixed q1_o;
		mfixed q2_i;
		mfixed q2_o;

		mfixed r0;  //constante
		mfixed r1_i;
		mfixed r1_o;

		mfixed s0; //constante

		mfixed p0; //constante

		mfixed p1_i;
		mfixed p1_o;
		mfixed p1_l;

		mfixed p2_i;
		mfixed p2_o;
		mfixed p2_l;

		mfixed p3_i;
		mfixed p3_o;
		mfixed p3_l;
			
		sc_out<bool> valid;
		
                sc_in<unsigned char>   x_i;
                sc_in<unsigned char>   y_i;
                sc_in<unsigned char>   x_o;
                sc_in<unsigned char>   y_o;

            protected:
                SC_HAS_PROCESS(IncrCalc);

	}
    }
}
