#include <math.h>
#include "waveform.h"

double compute_rms(WaveformSample*samples, int count, char phase) {
    double sum_sq=0.0;
    double value;
    for (int i = 0; i < count; i++) {
        if (phase == 'A')
            value= samples[i].phase_A_voltage;
        else if (phase == 'B')
            value= samples[i].phase_B_voltage;
        else
            value= samples[i].phase_C_voltage;
        sum_sq += value*value;
    }
    return sqrt(sum_sq/count);
}
double compute_peak_to_peak(WaveformSample*sample, int count, char phase) {
    double value;
    double min, max;
    if (phase=='A')
        max=min=sample[0].phase_A_voltage;
    else if (phase=='B')
        max=min=sample[0].phase_B_voltage;
    else
        max=min=sample[0].phase_C_voltage;
    for (int i = 0; i < count; i++) {
        if (phase=='A')
            value= sample[i].phase_A_voltage;
        else if (phase=='B')
            value= sample[i].phase_B_voltage;
        else
            value= sample[i].phase_C_voltage;
        if (value>max)
            max=value;
        if (value<min)
            min=value;
    }
    return max-min;
}
double compute_dc_offset(WaveformSample*sample, int count, char phase) {
    double sum=0.0;
    double value;
    for (int i = 0; i < count; i++) {
        if (phase=='A')
            value= sample[i].phase_A_voltage;
        else if (phase=='B')
            value= sample[i].phase_B_voltage;
        else
            value= sample[i].phase_C_voltage;
        sum += value;
    }
    return sum/count;
}
int count_clipped(WaveformSample*samples, int count, char phase) {
    int clipped=0;
    double value;
    for (int i = 0; i < count; i++) {
        if (phase =='A')
            value = samples[i].phase_A_voltage;
        else if (phase =='B')
            value= samples[i].phase_B_voltage;
        else
            value= samples[i].phase_C_voltage;
        if (fabs(value)>=324.9) clipped++;
    }
    return clipped;
}
int check_compliance(double rms) {
    return (rms >= 207.0 && rms <= 253.0);
}
double compute_frequency_range(WaveformSample*samples,int count) {
    double sum=0.0;
    for (int i = 0; i < count; i++) {
        sum+=samples[i].frequency;
    }
    return sum/count;
}
double compute_power_factor_range(WaveformSample*samples,int count) {
    double sum=0.0;
    for (int i = 0; i < count; i++) {
        sum+=samples[i].power_factor;
    }
    return sum/count;
}
double compute_thd_range(WaveformSample*samples,int count) {
    double sum=0.0;
    for (int i = 0; i < count; i++) {
        sum+=samples[i].thd_percent;
    }
    return sum/count;
}