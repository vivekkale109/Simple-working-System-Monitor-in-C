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

// ---------- RAM USAGE ----------
void get_ram_usage() {
    FILE *fp;
    char label[50];
    long total_mem = 0, free_mem = 0;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        return;
    }

    while (fscanf(fp, "%s %ld kB\n", label, &total_mem) != EOF) {
        if (strcmp(label, "MemTotal:") == 0) {
            total_mem = total_mem;
        } else if (strcmp(label, "MemAvailable:") == 0) {
            free_mem = total_mem;
            break;
        }
    }

    fclose(fp);

    long used = total_mem - free_mem;
    float usage = ((float)used / total_mem) * 100;

    printf("RAM Usage: %.2f%%\n", usage);
}

// ---------- DISK USAGE ----------
void get_disk_usage() {
    struct statvfs stat;

    if (statvfs("/", &stat) != 0) {
        perror("statvfs failed");
        return;
    }

    unsigned long total = stat.f_blocks * stat.f_frsize;
    unsigned long free = stat.f_bfree * stat.f_frsize;
    unsigned long used = total - free;

    float usage = ((float)used / total) * 100;

    printf("Disk Usage: %.2f%%\n", usage);
}