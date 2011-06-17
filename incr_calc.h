#define TILE_HEIGHT 16
#define TILE_WIDTH 16
#define IMAGE_HEIGHT 480
#define IMAGE_WIDTH 640
#define NO_TILES 1200

#include "systemc.h"

using namespace sc_core;
using namespace std;

namespace soclib { namespace caba {

    class IncrCalc
        :sc_module {

	private:
	    /*private line and column counter*/
	    int lin;
	    int col;
	    int tile;

	    int state;
	    /* 0 : WAIT
	       1 : Calculate
	       2 : Finished
	    */

	    /*methods*/
	    void calc();

            public:
                // IO PORTS

                sc_in_clk           clk;
                sc_in<bool>         reset_n;
		sc_in<bool>         p0_valid;
		sc_in<bool>         q0_valid;
		sc_in<bool>         q1_valid;
		sc_in<bool>         q2_valid;
		sc_in<bool>         r0_valid;
		sc_in<bool>         r1_valid;
		sc_in<bool>         s0_valid;
		sc_in<bool>         load;
		sc_in<float>          p0_in;		
		sc_in<float>          q0_in;
		sc_in<float>          q1_in;
		sc_in<float>          q2_in;
		sc_in<float>          q3_in;
		sc_in<float>          r0_in;
		sc_in<float>          r1_in;
		sc_in<float>          r2_in;
		sc_in<float>          s0_in;
		sc_in<float>          s1_in;
		
		sc_signal<bool> wait_cyc; //wait one cycle for signal to be valid
		
		/* registres */

		float q0;  //constante	
		sc_signal<float> q1;

		sc_signal<float> q2;

		sc_signal<float> q3;


		float r0;  //constante
		sc_signal<float> r1;
		sc_signal<float> r2;


		float s0; //constante
		sc_signal<float> s1;

		float p0; //constante

		sc_signal<float> p1;

		sc_signal<float> p1_l;

		sc_signal<float> p2;

		sc_signal<float> p2_l;

		sc_signal<float> p3;

		sc_signal<float> p3_l;
			
		sc_out<bool> o_valid;
		sc_out<bool> o_finished;
		
                sc_out<float>   x_3;
                sc_out<float>   x_2;
                sc_out<float>   x_1;

		IncrCalc(sc_module_name insname);

            protected:
                SC_HAS_PROCESS(IncrCalc);

	};
    }
}
