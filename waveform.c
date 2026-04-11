#include <math.h>
#include "waveform.h"

double compute_rms(WaveformSample *samples, int count) {
    double sum_sq = 0.0;

    for (int i = 0; i < count; i++) {
        sum_sq += samples[i].phase_A_voltage * samples[i].phase_A_voltage;
    }

    return sqrt(sum_sq / count);
}
double compute_peak_to_peak(WaveformSample *samples, int count) {
    double max = samples[0].phase_A_voltage;
    double min = samples[0].phase_A_voltage;

    for (int i = 1; i < count; i++) {
        if (samples[i].phase_A_voltage > max)
            max = samples[i].phase_A_voltage;

        if (samples[i].phase_A_voltage < min)
            min = samples[i].phase_A_voltage;
    }

    return max - min;
}

double compute_dc_offset(WaveformSample *samples, int count) {
    double sum = 0.0;

    for (int i = 0; i < count; i++) {
        sum += samples[i].phase_A_voltage;
    }

    return sum / count;
}