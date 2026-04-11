#include <math.h>
#include "waveform.h"

double compute_rms(WaveformSample *samples, int count) {
    double sum_sq = 0.0;

    for (int i = 0; i < count; i++) {
        sum_sq += samples[i].phase_A_voltage * samples[i].phase_A_voltage;
    }

    return sqrt(sum_sq / count);
}