#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>

// ---------- CPU USAGE ----------
void get_cpu_usage() {
    FILE *fp;
    long user, nice, system, idle;
    static long prev_total = 0, prev_idle = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return;
    }

    fscanf(fp, "cpu %ld %ld %ld %ld", &user, &nice, &system, &idle);
    fclose(fp);

    long total = user + nice + system + idle;
    long total_diff = total - prev_total;
    long idle_diff = idle - prev_idle;

    float cpu_usage = 0.0;
    if (total_diff != 0) {
        cpu_usage = (1.0 - ((float)idle_diff / total_diff)) * 100.0;
    }

    prev_total = total;
    prev_idle = idle;

    printf("CPU Usage: %.2f%%\n", cpu_usage);
}
