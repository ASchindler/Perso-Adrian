#include <systemc>

using namespace sc_core;
using namespace std;

namespace soclib { namespace caba {

    class IncrCalc
        :sc_module {

	private:
	    /*private line and column counter*/
	    int lin;
	    int col;

	    /*methods*/
	    void y_calc();
	    void x_calc();
	    void initialise_const();

            public:
                // IO PORTS

                sc_in_clk           clk;
                sc_in<bool>         reset_n;

		sc_signal<bool> wait_cyc; //wait one cycle for signal to be valid
		
                sc_signal<int>  x_a[10];
                sc_signal<int>  y_a[10];
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

		sc_signal<int>  x_b[6];
		/*
		  b[5] - b20
		  b[4] - b11
		  b[3] - b10
		  b[2] - b02
		  b[1] - b01
		  b[0] - b00
		*/
		sc_signal<int>  y_b[6];

		sc_signal<int>  x_c[3];
		/*
		  c[2] - c10
		  c[1] - c01
		  c[0] - c00	
		*/
		sc_signal<int>  y_c[3];

		/* registres */

		int q0;  //constante	
		sc_signal<int> q1;

		sc_signal<int> q2;


		int r0;  //constante
		sc_signal<int> r1;


		int s0; //constante

		int p0; //constante

		sc_signal<int> p1;

		sc_signal<int> p1_l;

		sc_signal<int> p2;

		sc_signal<int> p2_l;

		sc_signal<int> p3;

		sc_signal<int> p3_l;
			
		sc_out<bool> valid;
		
                //sc_in<unsigned char>   x_i;
                //sc_in<unsigned char>   y_i;
                sc_out<char>   x_3;
                sc_out<char>   x_2;
                sc_out<char>   x_1;

                //sc_in<unsigned char>   y_o;

		IncrCalc(sc_module_name insname);

            protected:
                SC_HAS_PROCESS(IncrCalc);

	};
    }
}
