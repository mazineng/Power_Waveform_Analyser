#ifndef IO_H
#define IO_H

#include "waveform.h"

WaveformSample* load_csv(const char *filename, int *count);
void write_results(const char*filename, double rmsA, double rmsB, double rmsC,int clippedA, int clippedB, int clippedC,
    int compliantA, int compliantB, int compliantC, double freq_range, double pf_range,double thd_range, double vppA,
    double vppB,double vppC, double dcA,double dcB,double dcC);
#endif