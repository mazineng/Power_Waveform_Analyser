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