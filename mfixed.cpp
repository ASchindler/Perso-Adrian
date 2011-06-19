#include "mfixed2.h"

mfixed::mfixed () 
{
    h = 0;
    l = 0;
}

mfixed::mfixed(int a)
{
    h = a;
    l = 0;
}

 mfixed::mfixed (int a, int b) 
{
    h = a;
    l = b;
    }


bool mfixed::operator == (const mfixed & rhs) const {
    return (rhs.h == h && rhs.l == l );
}

mfixed& mfixed::operator = (const mfixed& rhs)  {
    h = rhs.h;
    l = rhs.l;
    return *this;
}

//inline mfixed mfixed::operator + (const mfixed& rhs) {
mfixed operator + (const mfixed&    u, const mfixed&    v)
{
    mfixed temp;
    temp.h = u.h+v.h;
    temp.l = u.l+v.l;
    return (temp);
}

void sc_trace(sc_trace_file *tf, const mfixed & v,
				    const std::string & NAME ) {
    sc_trace(tf,v.h, NAME + ".h");
    sc_trace(tf,v.l, NAME + ".l");
}

// fixed point multiplication
mfixed fx_mul  (mfixed A, mfixed B)
{

    return (mfixed)( ((A.l*B.l)>> 16) +
            (A.l * B.h )    +
            (A.h * B.l )    +
            ((A.h*B.h) << 16)
            );
}

// fixed point addition
mfixed fx_add (mfixed A, mfixed B)
{
    return A+B;
}

ostream& operator << ( ostream& os,  mfixed const & v ) {
    os << "(" << v.h << "," << std::boolalpha << v.l << ")";
    return os;
}
