# Power Quality Waveform Analyser
Build of a C program that reads real world power quality data from a sensor log file, analyses the voltage waveforms, and produces a structured report.

How to compile and run the program

Using CLion:
1. Open CLion.
2. Click file then select Power_Waveform_Analyser folder.
3. Click Open
4. Click build then select build project
5. Click Run then click edit configurations 
6. Set working directory to project folder
7. Run project

Using gcc command

1. Compiling: gcc -std=c99 -Wall main.c waveform.c io.c -lm -o PowerAnalyser
2. Running program: ./PowerAnalyser power_quality_log.csv

Output:
1. RMS voltage of 3 phases that are around 229 V
2. peak to peak voltages of the 3 phases that are around 650V
3. Dc offset of 3 phases that are approximately 0V
4. Number of clipped samples which is 20 samples per phase
5. Frequency range which is around 50Hz
6. Power factor range, around 1
7. THD range, around  2.09%
8. "The analysis report is executed to file named results.txt"

GitHub Repository: https://github.com/mazineng/Power_Waveform_Analyser.git