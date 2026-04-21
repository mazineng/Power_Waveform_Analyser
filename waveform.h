#ifndef WAVEFORM_H
#define WAVEFORM_H

typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;
double compute_rms(WaveformSample*samples, int count,char phase);
double compute_peak_to_peak(WaveformSample*samples, int count, char phase);
double compute_dc_offset(WaveformSample*samples, int count, char phase);
int count_clipped(WaveformSample*samples, int count, char phase);
int check_compliance(double rms);
double compute_frequency_average(WaveformSample*samples,int count);
double compute_power_factor_average(WaveformSample*samples,int count);
double compute_thd_average(WaveformSample*samples,int count);
#endif
