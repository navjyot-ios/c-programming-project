/* Simple in-memory violation module for beginner-level code */

#include <stdio.h>
#include <string.h>
#include "violation.h"

static Violation viols[MAX_VIOLS];
static int viol_count = 0;
static int next_id = 1;

int record_violation(void) {
    if (viol_count >= MAX_VIOLS) { printf("Cannot record more violations.\n"); return 0; }
    Violation *v = &viols[viol_count];
    v->id = next_id++;
    printf("Enter vehicle reg no: ");
    if (!fgets(v->reg, sizeof(v->reg), stdin)) return 0;
    v->reg[strcspn(v->reg, "\n")] = '\0';
    printf("Enter violation type: ");
    if (!fgets(v->type, sizeof(v->type), stdin)) return 0;
    v->type[strcspn(v->type, "\n")] = '\0';
    v->fine = 100; /* simple fixed fine */
    v->paid = 0;
    viol_count++;
    printf("Violation recorded. ID=%d\n", v->id);
    return 1;
}

int list_violations(void) {
    if (viol_count == 0) { printf("No violations.\n"); return 0; }
    printf("ID\tReg\tType\tFine\tPaid\n");
    for (int i = 0; i < viol_count; i++) {
        printf("%d\t%s\t%s\t%d\t%s\n", viols[i].id, viols[i].reg, viols[i].type, viols[i].fine, viols[i].paid ? "Yes" : "No");
    }
    return 1;
}

int mark_violation_paid(void) {
    int id;
    printf("Enter violation ID to mark paid: ");
    if (scanf("%d%*c", &id) != 1) { printf("Invalid\n"); return 0; }
    for (int i = 0; i < viol_count; i++) {
        if (viols[i].id == id) {
            if (viols[i].paid) { printf("Already paid.\n"); return 0; }
            viols[i].paid = 1;
            printf("Marked paid for ID %d\n", id);
            return 1;
        }
    }
    printf("Violation ID not found.\n");
    return 0;
}

int violation_count(void) { return viol_count; }
int pending_count(void) { int c = 0; for (int i=0;i<viol_count;i++) if (!viols[i].paid) c++; return c; }