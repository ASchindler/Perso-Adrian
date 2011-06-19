#include "mfixed.h"

mfixed::mfixed () 
{
    h = 0;
    l = 0;
}

/*mfixed1(int a)
{
    h = a;
    l = 0;
    }*/

 /*mfixed::mfixed (int a, double b) 
{
    h = a;
    l = b / 100000000000;
    }*/

/*
inline bool mfixed::operator == (const mfixed & rhs) const {
    return (rhs.h == h && rhs.l == l );
}

inline mfixed& mfixed::operator = (const mfixed& rhs)  {
    h = rhs.h;
    l = rhs.l;
    return *this;
}

inline friend mfixed::mfixed& operator + (const mfixed& rhs) {
    mfixed temp;
    temp.h = h+rhs.h;
    temp.l = l+rhs.l;
    return (temp);
}

inline friend void mfixed::sc_trace(sc_trace_file *tf, const mfixed & v,
				    const std::string & NAME ) {
    sc_trace(tf,v.h, NAME + ".h");
    sc_trace(tf,v.l, NAME + ".l");
}

inline friend ostream& mfixed::operator << ( ostream& os,  mfixed const & v ) {
    os << "(" << v.h << "," << std::boolalpha << v.l << ")";
    return os;
}

inline mfixed mfixed1 (int A)
{
    mfixed new1;
    new1.h = (short)A;
    new1.l = 0;
    return new1;
}



inline void mfixed::fx_copy (mfixed A, mfixed B)
{
    B.l = A.l;
    B.h = A.h;
}


// fixed point multiplication
inline mfixed mfixed::fx_mul  (mfixed A, mfixed B)
{

    return (mfixed)( ((A.l*B.l)>> 16) +
		     (A.l * B.h )    +
		     (A.h * B.l )    +
		     ((A.h*B.h) << 16)
	);
}

// fixed point addition
inline mfixed mfixed::fx_add (mfixed A, mfixed B)
{
    return (mfixed)(A.all + B.all);
}

*/

