//#include "../tmp/sfp/lib/sfp.hh"
#define MEX

#ifdef MEX
#include "mex.h"
#endif

#include "sfp.hh"
#include <cstdio>
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

#define I_real prhs[0]
#define I_imag prhs[1]
#define O_real plhs[0]
#define O_imag plhs[1]
#define I_length prhs[2]

void FFT_1D_Double(double *input_real, double *input_imag, double *output_real, double *output_imag, int length)
{
    unsigned *F1_real = new unsigned[length];
    unsigned *F1_imag = new unsigned[length];
    unsigned *F2_real = new unsigned[length];
    unsigned *F2_imag = new unsigned[length];
    // int max_num = 0;
    // int max_exp = -9;
    // double max_double;
    // auto max_SFP = SFP(exponent , mantissa);
    SFP p[4] = {SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa)};
    // for(int i = 0;i<length;i++){
    //     p[0].set(input_real[i]);
    //     p[1].set(input_imag[i]);
    //     // cout<<p[0].exp() << "   "<<p[1].exp()<<"  "<<max_exp<<endl;
    //     // p[0].print();
    //     // p[1].print();
    //     if(p[0].exp() > max_exp){
    //         max_exp = p[0].exp();
    //         max_num = i;
    //         // cout<<max_exp<<"  "<<max_num<<endl;
    //     }
    //     else if(p[1].exp() > max_exp){
    //         max_exp = p[1].exp();
    //         max_num = i + length;
    //         // cout<<max_exp<<"  "<<max_num<<endl;
    //     }
    //     else{
    //     }
    // }

    // if(max_num>=length){
    //     max_double = input_imag[max_num - length];
    // }else{
    //     max_double = input_real[max_num];
    // }
    // // cout<<max_num<<"  "<<max_double<<endl;
    // if(max_double == 0){
    for (int i = 0; i < length; i++)
    {
        F1_real[i] = (p[0].set(input_real[i])).getBits();
        F1_imag[i] = (p[1].set(input_imag[i])).getBits();
    }
    // }else{
    //    for(int i=0;i<length;i++){
    //        F1_real[i] = (p[0].set(input_real[i]/max_double)).getBits();
    //        F1_imag[i] = (p[1].set(input_imag[i]/max_double)).getBits();
    //     //    F1_real[i] = (p[0].set(input_real[i])).getBits();
    //     //    F1_imag[i] = (p[1].set(input_imag[i])).getBits();
    //     //    p[0].print();
    //     //    p[1].print();
    //    }
    // }

    // FFT_1D(F1_real , F1_imag , F2_real , F2_imag , length);
    FFT_1D_SIZE4(F1_real, F1_imag, F2_real, F2_imag, length);
    for (int i = 0; i < length; i++)
    {
        // output_real[i] = (p[2].setBits(F2_real[i])).getDouble() * max_double;
        // output_imag[i] = (p[3].setBits(F2_imag[i])).getDouble() * max_double;
        output_real[i] = (p[2].setBits(F2_real[i])).getDouble();
        output_imag[i] = (p[3].setBits(F2_imag[i])).getDouble();
    }
}
#ifdef MEX
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    double *input_real, *input_imag, *output_real, *output_imag;
    int length;
    length = mxGetNumberOfElements(I_real);
    if (*(mxGetPr(I_length)) != length)
    {
        mexErrMsgIdAndTxt("MATLAB:length is error", "length is error");
    }

    O_real = mxCreateDoubleMatrix(length, 1, mxREAL);
    O_imag = mxCreateDoubleMatrix(length, 1, mxREAL);

    input_real = mxGetPr(I_real);
    input_imag = mxGetPr(I_imag);
    output_real = mxGetPr(O_real);
    output_imag = mxGetPr(O_imag);

    FFT_1D_Double(input_real, input_imag, output_real, output_imag, length);
    // plhs[1] = mxCreateDoubleMatrix();
}
#endif