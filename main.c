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

    printf("number of rows : %d\n", count);
    printf("1st timestamp: %.4f\n", samples[0].timestamp);

    free(samples);
    return 0;
}