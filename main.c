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

    double rmsA = compute_rms(samples, count,'A');
    double rmsB = compute_rms(samples, count,'B');
    double rmsC = compute_rms(samples, count,'C');
    double vppA = compute_peak_to_peak(samples, count, 'A');
    double vppB = compute_peak_to_peak(samples, count, 'B');
    double vppC = compute_peak_to_peak(samples, count, 'C');
    double dcA = compute_dc_offset(samples, count, 'A');
    double dcB = compute_dc_offset(samples, count, 'B');
    double dcC = compute_dc_offset(samples, count, 'C');
    int clippedA = count_clipped(samples, count, 'A');
    int clippedB = count_clipped(samples, count, 'B');
    int clippedC = count_clipped(samples, count, 'C');
    int compliantA = check_compliance(rmsA);
    int compliantB = check_compliance(rmsB);
    int compliantC = check_compliance(rmsC);
    printf("Phase A RMS Voltage: %.4f \n",rmsA);
    printf("Phase B RMS Voltage: %.4f \n", rmsB);
    printf("Phase C RMS Voltage: %.4f \n", rmsC);
    printf("Phase A Peak to Peak: %.4f V\n", vppA);
    printf("Phase B Peak to Peak: %.4f V\n", vppB);
    printf("Phase C Peak to Peak: %.4f V\n", vppC);
    printf("Phase A DC Offset: %.4f V\n", dcA);
    printf("Phase B DC Offset: %.4f V\n", dcB);
    printf("Phase C DC Offset: %.4f V\n", dcC);
    printf("Clipped samples in phase A: %d \n", clippedA);
    printf("Clipped samples in phase B: %d \n", clippedB);
    printf("Clipped samples in phase C: %d \n", clippedC);
    printf("Compliance of phase A: %s \n,",compliantA? "Compliant":"Not Compliant");
    printf("Compliance of phase B: %s \n",compliantB? "Compliant":"Not Compliant");
    printf("Compliance of phase C: %s \n",compliantC? "Compliant":"Not Compliant");
    free(samples);
    return 0;
}