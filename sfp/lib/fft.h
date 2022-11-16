#include "sfp.hh"

#define exponent 4
#define mantissa 4
     

void FFT_1D(unsigned *input_real , unsigned *input_imag , unsigned *output_real , unsigned *output_imag , int length);

void FFT_1D_Double(double *input_real , double *input_imag , double *output_real , double *output_imag , int length);