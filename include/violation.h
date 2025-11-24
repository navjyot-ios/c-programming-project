#ifndef VIOLATION_H
#define VIOLATION_H

#define MAX_VIOLS 100
#define MAX_REG 20
#define MAX_TYPE 30

typedef struct {
    int id;
    char reg[MAX_REG];
    char type[MAX_TYPE];
    int fine;
    int paid; /* 0 = no, 1 = yes */
} Violation;

/* Simple violation functions */
int record_violation(void);
int list_violations(void);
int mark_violation_paid(void);
int violation_count(void);
int pending_count(void);

#endif /* VIOLATION_H */
