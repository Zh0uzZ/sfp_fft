#include "sfp.hh"

#include <cstdio>
#include <iostream>
using std::cout;
using std::endl;
#define num 32
int main(int argc, char *argv[])
{
//   auto p = SFP(3, 3);
//   for (unsigned i = 0; i < (unsigned)(1 << p.nBits()); i++) {
//       p.setBits(i);
//       p.print();
//   }

    SFP p[4] = {SFP(exponent,mantissa) , SFP(exponent,mantissa) , SFP(exponent,mantissa) , SFP(exponent,mantissa)};
    // double input_real[num] = {1,2,3,4};
    // double input_imag[num] = {1,1,1,1};

    // double input_real[num] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,15};
    // double input_imag[num] = {1,4,5,10,1,1,1,1,1,1,1,1,1,1,1,1};
    double input_real[num] = {0.100000,0.200000,0.300000,0.400000,0.500000,0.600000,0.700000,0.800000,0.900000,1.000000,1.100000,1.200000,1.300000,1.400000,1.500000,1.600000,1.700000,1.800000,1.900000,2.000000,2.100000,2.200000,2.300000,2.400000,2.500000,2.600000,2.700000,2.800000,2.900000,3.000000,3.100000,3.200000};
    double input_imag[num] = {0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000};

    double output_real[num];
    double output_imag[num];
    int length;
    length = sizeof(input_real) / sizeof(double);
    // p[0].set(0.4);p[0].print();
    // p[1].set(0.8);p[1].print();
    // ((p[0]+p[1]).resizeTo(4,4)).print();

    // cout<<length<<endl;
    FFT_1D_Double(input_real , input_imag , output_real , output_imag , length);
    for(int i=0;i<num;i++){
        cout<<output_real[i]<<"   "<<output_imag[i]<<"i"<<endl;
    }
    return 0;
}
