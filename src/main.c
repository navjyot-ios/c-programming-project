/* Beginner-friendly main.c - simple menu and calls into modules */

#include <stdio.h>
#include "vehicle.h"
#include "violation.h"
#include "reports.h"

static void wait_enter(void) {
    printf("Press Enter to continue...");
    getchar();
}

int main(void) {
    int choice = 0;
    while (1) {
        printf("\nSimple Traffic System - Beginner Version\n");
        printf("1. Add Vehicle\n");
        printf("2. List Vehicles\n");
        printf("3. Record Violation\n");
        printf("4. List Violations\n");
        printf("5. Pay Violation\n");
        printf("6. Reports\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d%*c", &choice) != 1) break;

        if (choice == 0) break;
        if (choice == 1) add_vehicle();
        else if (choice == 2) list_vehicles();
        else if (choice == 3) record_violation();
        else if (choice == 4) list_violations();
        else if (choice == 5) mark_violation_paid();
        else if (choice == 6) {
            printf("Reports:\n");
            printf("Total violations: %d\n", violation_count());
            printf("Pending payments: %d\n", pending_count());
        }
        else printf("Invalid choice\n");

        wait_enter();
    }

    printf("Goodbye!\n");
    return 0;
}