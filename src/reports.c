
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "reports.h"
#include "violation.h"
#include "vehicle.h"

static const char *VIOL_FILE = "violations.txt";

/* daily collection report - sums all paid fines */
int daily_collection_report(void) {
    FILE *f = fopen("payments.txt", "r");
    if(!f) { printf("No payments recorded.\n"); return 0; }
    char line[128];
    int total = 0;
    printf("PaymentID\tAmount\n");
    printf("---------------------\n");
    while(fgets(line, sizeof(line), f)) {
        int id, amt;
        if(sscanf(line, "%d,%d", &id, &amt)==2) {
            printf("%d\t\t%d\n", id, amt);
            total += amt;
        }
    }
    fclose(f);
    printf("---------------------\nTotal collection: %d\n", total);
    return 1;
}

int pending_fines_report(void) {
    FILE *f = fopen(VIOL_FILE, "r");
    if(!f) { printf("No violations.\n"); return 0; }
    char line[256];
    int found = 0;
    printf("ID\tRegNo\tFine\n");
    printf("------------------------\n");
    while(fgets(line, sizeof(line), f)) {
        int id, fine, paid;
        char reg[MAX_REG], type[64], date[16];
        if(sscanf(line, "%d,%15[^,],%63[^,],%15[^,],%d,%d", &id, reg, type, date, &fine, &paid)==6) {
            if(!paid) { found = 1; printf("%d\t%s\t%d\n", id, reg, fine); }
        }
    }
    fclose(f);
    if(!found) printf("No pending fines.\n");
    return found;
}

/* find top offenders by number of violations */
int top_offenders_report(void) {
    FILE *f = fopen(VIOL_FILE, "r");
    if(!f) { printf("No violations.\n"); return 0; }
    /* naive approach: read into memory and count */
    typedef struct { char reg[MAX_REG]; int count; } Entry;
    Entry arr[1000];
    int n = 0;

    char line[256];
    while(fgets(line, sizeof(line), f)) {
        int id, fine, paid;
        char reg[MAX_REG], type[64], date[16];
        if(sscanf(line, "%d,%15[^,],%63[^,],%15[^,],%d,%d", &id, reg, type, date, &fine, &paid)==6) {
            int i;
            for(i=0;i<n;i++) {
                if(strcmp(arr[i].reg, reg)==0) { arr[i].count++; break; }
            }
            if(i==n && n < 1000) {
                strcpy(arr[n].reg, reg); arr[n].count = 1; n++;
            }
        }
    }
    fclose(f);
    if(n==0) { printf("No offenders.\n"); return 0; }
    /* simple selection sort descending */
    for(int i=0;i<n-1;i++) {
        int max=i;
        for(int j=i+1;j<n;j++) if(arr[j].count > arr[max].count) max=j;
        if(max!=i) { Entry tmp = arr[i]; arr[i]=arr[max]; arr[max]=tmp; }
    }
    printf("Top offenders:\nRegNo\tCount\n");
    printf("-----------------\n");
    int limit = (n<5)?n:5;
    for(int i=0;i<limit;i++) printf("%s\t%d\n", arr[i].reg, arr[i].count);
    return 1;
}