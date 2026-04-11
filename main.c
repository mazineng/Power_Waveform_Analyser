#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main() {
    int count;
    WaveformSample *samples = load_csv("power_quality_log.csv", &count);

    if (samples == NULL) {
        return 1;
    }

    double rms = compute_rms(samples, count);
    printf("number of rows : %d\n", count);
    printf("Phase A RMS: %.2f\n", rms);

    free(samples);
    return 0;
}