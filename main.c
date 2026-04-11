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
    double vpp = compute_peak_to_peak(samples, count);
    double dc = compute_dc_offset(samples, count);
    int clipped= count_clipped(samples, count);
    int compliant= check_compliance(rms);
    printf("Phase A Peak-to-Peak: %.2f V\n", vpp);
    printf("Phase A DC Offset: %.2f V\n", dc);
    printf("Clipped samples: %d \n", clipped);
    printf("Compliance: %s \n,", compliant? "Compliant":"Not Compliant");
    free(samples);
    return 0;
}