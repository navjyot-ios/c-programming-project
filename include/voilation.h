#ifndef VIOLATION_H
#define VIOLATION_H

#include "vehicle.h"

#define MAX_VIOL_TYPE 32
#define MAX_DATE 16

typedef struct {
    int id;
    char reg_no[MAX_REG];
    char vtype[MAX_VIOL_TYPE];
    char date[MAX_DATE]; /* dd-mm-yyyy */
    int fine;
    int paid; /* 0 = unpaid, 1 = paid */
} Violation;

int record_violation();
int list_violations();
int list_violations_for_vehicle(const char *reg);
int mark_violation_paid();
int generate_reports();

#endif