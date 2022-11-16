//#include "../tmp/sfp/lib/sfp.hh"
#include "fft.h"
#include "twiddle.h"
#include <iostream>

using std::cout;
using std::endl;

// SFP *F1_real = malloc(sizeof(SFP));
void FFT_1D_SIZE4(unsigned *input_real, unsigned *input_imag, unsigned *output_real, unsigned *output_imag, int length)
{
    // int length = sizeof(input)/sizeof(unsigned);
    // int flag = length/128;
    unsigned *F1_real = new unsigned[length];
    unsigned *F1_imag = new unsigned[length];
    unsigned *temp_real = new unsigned[length];
    unsigned *temp_imag = new unsigned[length];
    unsigned temp;
    // cout<<length<<endl;
    SFP p[8] = {SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa)};
    SFP q[8] = {SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa)};
    SFP o[8] = {SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa), SFP(exponent, mantissa)};
    if (length == 2)
    {
        for (int i = 0; i < length / 2; i++)
        {
            q[0] = (p[0].setBits(input_real[i]) + p[1].setBits(input_real[i + length / 2])); //第一列real
            q[1] = (p[2].setBits(input_real[i]) - p[3].setBits(input_real[i + length / 2])); //第二列real
            q[2] = (p[0].setBits(input_imag[i]) + p[1].setBits(input_imag[i + length / 2])); //第一列imag
            q[3] = (p[2].setBits(input_imag[i]) - p[3].setBits(input_imag[i + length / 2])); //第二列imag

            output_real[i] = q[0].getBits();
            output_real[i + length / 2] = q[1].getBits();
            output_imag[i] = q[2].getBits();
            output_imag[i + length / 2] = q[3].getBits();
        }
    }
    else if (length == 4)
    {
        q[0] = (p[0].setBits(input_real[i]) + p[1].setBits(input_real[i + length / 4]) + p[2].setBits(input_real[i + length / 2]) + p[3].setBits(input_real[i + length / 4 * 3])); //第一列real
        q[1] = (p[0].setBits(input_real[i]) - p[1].setBits(input_real[i + length / 2]) - p[2].setBits(input_imag[i + length / 4]) + p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real
        q[2] = (p[0].setBits(input_real[i]) - p[1].setBits(input_real[i + length / 4]) + p[2].setBits(input_real[i + length / 2]) - p[3].setBits(input_real[i + length / 4 * 3])); //第一列real
        q[3] = (p[0].setBits(input_real[i]) - p[1].setBits(input_real[i + length / 2]) + p[2].setBits(input_imag[i + length / 4]) - p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real

        q[4] = (p[4].setBits(0) - p[0].setBits(input_imag[i]) - p[1].setBits(input_imag[i + length / 4]) - p[2].setBits(input_imag[i + length / 2]) - p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real
        q[5] = (p[4].setBits(0) - p[0].setBits(input_real[i + length / 4]) - p[1].setBits(input_real[i + length / 4 * 3]) - p[2].setBits(input_imag[i]) + p[3].setBits(input_imag[i + length / 2])); //第一列real
        q[6] = (p[4].setBits(0) - p[0].setBits(input_imag[i]) + p[1].setBits(input_imag[i + length / 4]) - p[2].setBits(input_imag[i + length / 2]) + p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real
        q[7] = (p[4].setBits(0) + p[0].setBits(input_real[i + length / 4]) - p[1].setBits(input_real[i + length / 4 * 3]) - p[2].setBits(input_imag[i]) + p[3].setBits(input_imag[i + length / 2])); //第一列real

        for (int i = 0; i < length / 4; i++)
        {
            temp_real[i * 4] = output_real[i];
            temp_real[i * 4 + 1] = output_real[i + length / 4];
            temp_real[i * 4 + 2] = output_real[i + length / 2];
            temp_real[i * 4 + 3] = output_real[i + length / 4 * 3];
            temp_imag[i * 4] = output_imag[i];
            temp_imag[i * 4 + 1] = output_imag[i + length / 4];
            temp_imag[i * 4 + 2] = output_imag[i + length / 2];
            temp_imag[i * 4 + 3] = output_imag[i + length / 4 * 3];
        }
        for (int i = 0; i < length; i++)
        {
            output_real[i] = temp_real[i];
            output_imag[i] = temp_imag[i];
        }
    }
    else
    {
        for (int i = 0; i < length / 4; i++)
        {
            q[0] = (p[0].setBits(input_real[i]) + p[1].setBits(input_real[i + length / 4]) + p[2].setBits(input_real[i + length / 2]) + p[3].setBits(input_real[i + length / 4 * 3])); //第一列real
            q[1] = (p[0].setBits(input_real[i]) - p[1].setBits(input_real[i + length / 2]) - p[2].setBits(input_imag[i + length / 4]) + p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real
            q[2] = (p[0].setBits(input_real[i]) - p[1].setBits(input_real[i + length / 4]) + p[2].setBits(input_real[i + length / 2]) - p[3].setBits(input_real[i + length / 4 * 3])); //第一列real
            q[3] = (p[0].setBits(input_real[i]) - p[1].setBits(input_real[i + length / 2]) + p[2].setBits(input_imag[i + length / 4]) - p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real

            q[4] = (p[4].setBits(0) - p[0].setBits(input_imag[i]) - p[1].setBits(input_imag[i + length / 4]) - p[2].setBits(input_imag[i + length / 2]) - p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real
            q[5] = (p[4].setBits(0) - p[0].setBits(input_real[i + length / 4]) - p[1].setBits(input_real[i + length / 4 * 3]) - p[2].setBits(input_imag[i]) + p[3].setBits(input_imag[i + length / 2])); //第一列real
            q[6] = (p[4].setBits(0) - p[0].setBits(input_imag[i]) + p[1].setBits(input_imag[i + length / 4]) - p[2].setBits(input_imag[i + length / 2]) + p[3].setBits(input_imag[i + length / 4 * 3])); //第一列real
            q[7] = (p[4].setBits(0) + p[0].setBits(input_real[i + length / 4]) - p[1].setBits(input_real[i + length / 4 * 3]) - p[2].setBits(input_imag[i]) + p[3].setBits(input_imag[i + length / 2])); //第一列real
            // cout<<q[1].getFloat()<<"  "<<q[3].getFloat()<<"i"<<endl;
            // cout<<input_real[i]<<"  "<<input_real[i+length/2]<<endl;
            // q[0].print();
            // q[1].print();

            p[0] = (q[0] * o[0].set(FN1024_REAL[i * 1024 * 4 / length])) - (q[4] * o[1].set(FN1024_IMAG[i * 1024 * 4 / length]));         //第一列real
            p[1] = (q[1] * o[0].set(FN1024_REAL[i * 1024 * 4 / length + 1])) - (q[5] * o[1].set(FN1024_IMAG[i * 1024 * 4 / length + 1])); //第一列real
            p[2] = (q[2] * o[0].set(FN1024_REAL[i * 1024 * 4 / length + 2])) - (q[6] * o[1].set(FN1024_IMAG[i * 1024 * 4 / length + 2])); //第一列real
            p[3] = (q[3] * o[0].set(FN1024_REAL[i * 1024 * 4 / length + 3])) - (q[7] * o[1].set(FN1024_IMAG[i * 1024 * 4 / length + 3])); //第一列real

            p[4] = (q[0] * o[0].set(FN1024_IMAG[i * 1024 * 4 / length])) + (q[4] * o[1].set(FN1024_REAL[i * 1024 * 4 / length]));         //第一列real
            p[5] = (q[1] * o[0].set(FN1024_IMAG[i * 1024 * 4 / length + 1])) + (q[5] * o[1].set(FN1024_REAL[i * 1024 * 4 / length + 1])); //第一列real
            p[6] = (q[2] * o[0].set(FN1024_IMAG[i * 1024 * 4 / length + 2])) + (q[6] * o[1].set(FN1024_REAL[i * 1024 * 4 / length + 2])); //第一列real
            p[7] = (q[3] * o[0].set(FN1024_IMAG[i * 1024 * 4 / length + 3])) + (q[7] * o[1].set(FN1024_REAL[i * 1024 * 4 / length + 3])); //第一列real
            // cout<<p[2].getFloat()<<"  "<<p[3].getFloat()<<"i"<<endl;
            // p[0].print();
            // p[1].print();
            // p[2].print();
            // p[3].print();
            F1_real[i] = p[0].getBits();
            F1_real[i + length / 4] = p[1].getBits();
            F1_real[i + length / 2] = p[2].getBits();
            F1_real[i + length / 4 * 3] = p[3].getBits();

            F1_imag[i] = p[4].getBits();
            F1_imag[i + length / 4] = p[5].getBits();
            F1_imag[i + length / 2] = p[6].getBits();
            F1_imag[i + length / 4 * 3] = p[7].getBits();
        }
        FFT_1D_SIZE4(F1_real, F1_imag, output_real, output_imag, length / 4);
        FFT_1D_SIZE4(F1_real + length / 4, F1_imag + length / 4, output_real + length / 4, output_imag + length / 4, length / 4);
        FFT_1D_SIZE4(F1_real + length / 2, F1_imag + length / 2, output_real + length / 2, output_imag + length / 2, length / 4);
        FFT_1D_SIZE4(F1_real + length / 4 * 3, F1_imag + length / 4 * 3, output_real + length / 4 * 3, output_imag + length / 4 * 3, length / 4);
        for (int i = 0; i < length / 4; i++)
        {
            temp_real[i * 4] = output_real[i];
            temp_real[i * 4 + 1] = output_real[i + length / 4];
            temp_real[i * 4 + 2] = output_real[i + length / 2];
            temp_real[i * 4 + 3] = output_real[i + length / 4 * 3];
            temp_imag[i * 4] = output_imag[i];
            temp_imag[i * 4 + 1] = output_imag[i + length / 4];
            temp_imag[i * 4 + 2] = output_imag[i + length / 2];
            temp_imag[i * 4 + 3] = output_imag[i + length / 4 * 3];
        }
        for (int i = 0; i < length; i++)
        {
            output_real[i] = temp_real[i];
            output_imag[i] = temp_imag[i];
        }
    }

    //  if(length == 2) {
    //      for (int i = 0; i <length/2 ; i++) {
    //          q[0].set(p[0].setBits(input_real[i]) + p[1].setBits(input_real[i+length/2]));  //第一列real
    //          q[1].set(p[2].setBits(input_real[i]) - p[3].setBits(input_real[i+length/2]));  //第二列real
    //          q[2].set(p[0].setBits(input_imag[i]) + p[1].setBits(input_imag[i+length/2]));  //第一列imag
    //          q[3].set(p[2].setBits(input_imag[i]) - p[3].setBits(input_imag[i+length/2]));  //第二列imag

    //          output_real[i]          = q[0].getBits();
    //          output_real[i+length/2] = q[1].getBits();
    //          output_imag[i]          = q[2].getBits();
    //          output_imag[i+length/2] = q[3].getbit();
    //      }
    //  }
    //  else {
    //      for (int i = 0; i <length/2 ; i++) {

    //          q[0].set(p[0].setBits(input_real[i]) + p[1].setBits(input_real[i+length/2]));  //第一列real
    //          q[1].set(p[2].setBits(input_real[i]) - p[3].setBits(input_real[i+length/2]));  //第二列real
    //          q[2].set(p[0].setBits(input_imag[i]) + p[1].setBits(input_imag[i+length/2]));  //第一列imag
    //          q[3].set(p[2].setBits(input_imag[i]) - p[3].setBits(input_imag[i+length/2]));  //第二列imag
    //          p[0] = q[0] * o[0].set(FN1024_REAL[i*4]) - q[2] * o[1].set(FN1024_IMAG[i*4]);//第一列real
    //          p[1] = q[0] * o[2].set(FN1024_IMAG[i*4]) + q[2] * o[3].set(FN1024_REAL[i*4]);//第一列imag
    //          p[2] = q[1] * o[0].set(FN1024_REAL[i*4+2]) - q[3] * o[1].set(FN1024_IMAG[i*4+2]);//第二列real
    //          p[3] = q[1] * o[2].set(FN1024_IMAG[i*4+2]) + q[3] * o[3].set(FN1024_REAL[i*4+2]);//第二列imag

    //          F1_real[i]          = p[0].getBits();
    //          F1_real[i+length/2] = p[2].getBits();
    //          F1_imag[i]          = p[1].getBits();
    //          F1_imag[i+length/2] = p[3].getbit();
    //      }
    //      FFT_1D(F1_real , F1_imag , output_real , output_imag , length/2);
    //      FFT_1D(F1_real + length/2 , F1_imag + length/2 , output_real + length/2 , output_imag + length/2 , length/2);
    //  }

    delete[] F1_real;
    delete[] F1_imag;
    delete[] temp_real;
    delete[] temp_imag;
    // for(int i = 0;i < length/4; i++){
    //     temp = output_real[i*4 + 1];
    //     output_real[i*4 + 1] = output_real[i*4 + 2];
    //     output_real[i*4 + 2] = temp;
    //     temp = output_imag[i*4 + 1];
    //     output_imag[i*4 + 1] = output_imag[i*4 + 2];
    //     output_imag[i*4 + 2] = temp;
    // }
}