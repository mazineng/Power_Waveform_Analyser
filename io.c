#include <stdio.h>
#include <stdlib.h>
#include "io.h"

WaveformSample* load_csv(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening CSV file.\n");
        return NULL;
    }
    char line[256];

    fgets(line, sizeof(line), file);

    int rows = 0;
    while (fgets(line, sizeof(line), file)) {
        rows++;
    }
    *count = rows;
    WaveformSample *samples = malloc(rows * sizeof(WaveformSample));
    if (samples == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return NULL;
    }
    rewind(file);
    fgets(line, sizeof(line), file);

    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
               &samples[i].timestamp,
               &samples[i].phase_A_voltage,
               &samples[i].phase_B_voltage,
               &samples[i].phase_C_voltage,
               &samples[i].line_current,
               &samples[i].frequency,
               &samples[i].power_factor,
               &samples[i].thd_percent);
        i++;
    }
    fclose(file);
    return samples;
}
void write_results(const char*filename, double rmsA, double rmsB, double rmsC,int clippedA, int clippedB, int clippedC,
    int compliantA, int compliantB, int compliantC, double freq_average, double pf_average,double thd_average, double vppA,
    double vppB,double vppC, double dcA,double dcB,double dcC) {
    FILE*file= fopen(filename, "w");
    if (file ==NULL) {
        printf("Error writing results.\n");
        return;
    }
    fprintf(file,"Phase A RMS Voltage: %.4f \n",rmsA);
    fprintf(file,"Phase B RMS Voltage: %.4f \n", rmsB);
    fprintf(file,"Phase C RMS Voltage: %.4f \n", rmsC);
    fprintf(file,"Phase A Peak to Peak: %.4f V\n", vppA);
    fprintf(file,"Phase B Peak to Peak: %.4f V\n", vppB);
    fprintf(file,"Phase C Peak to Peak: %.4f V\n", vppC);
    fprintf(file,"Phase A DC Offset: %.4f V\n", dcA);
    fprintf(file,"Phase B DC Offset: %.4f V\n", dcB);
    fprintf(file,"Phase C DC Offset: %.4f V\n", dcC);
    fprintf(file,"Clipped samples in phase A: %d \n", clippedA);
    fprintf(file,"Clipped samples in phase B: %d \n", clippedB);
    fprintf(file,"Clipped samples in phase C: %d \n", clippedC);
    fprintf(file,"Compliance of phase A: %s \n",compliantA? "Compliant":"Not Compliant");
    fprintf(file,"Compliance of phase B: %s \n",compliantB? "Compliant":"Not Compliant");
    fprintf(file,"Compliance of phase C: %s \n",compliantC? "Compliant":"Not Compliant");
    fprintf(file,"Average Frequency: %.4f Hz\n",freq_average);
    fprintf(file,"Average Power Factor: %.4f \n",pf_average);
    fprintf(file,"Average Total Harmonic Distortion: %.4f%\n",thd_average);
    fclose(file);
}