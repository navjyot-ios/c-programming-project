/* Vehicle module: file-backed implementation */
/* Simple vehicle module for beginner-level code */

#include <stdio.h>
#include <string.h>
#include "vehicle.h"

/* simple in-memory store */
static Vehicle vehicles[50];
static int vehicle_count = 0;

int add_vehicle(void) {
    if (vehicle_count >= 50) {
        printf("Cannot add more vehicles.\n");
        return 0;
    }
    printf("Enter reg no: ");
    if (!fgets(vehicles[vehicle_count].reg, sizeof(vehicles[vehicle_count].reg), stdin)) return 0;
    vehicles[vehicle_count].reg[strcspn(vehicles[vehicle_count].reg, "\n")] = '\0';
    printf("Enter owner name: ");
    if (!fgets(vehicles[vehicle_count].owner, sizeof(vehicles[vehicle_count].owner), stdin)) return 0;
    vehicles[vehicle_count].owner[strcspn(vehicles[vehicle_count].owner, "\n")] = '\0';
    printf("Enter vehicle type: ");
    if (!fgets(vehicles[vehicle_count].vtype, sizeof(vehicles[vehicle_count].vtype), stdin)) return 0;
    vehicles[vehicle_count].vtype[strcspn(vehicles[vehicle_count].vtype, "\n")] = '\0';
    vehicle_count++;
    printf("Vehicle added.\n");
    return 1;
}

int list_vehicles(void) {
    if (vehicle_count == 0) { printf("No vehicles.\n"); return 0; }
    printf("RegNo\tOwner\tType\n");
    for (int i = 0; i < vehicle_count; i++) {
        printf("%s\t%s\t%s\n", vehicles[i].reg, vehicles[i].owner, vehicles[i].vtype);
    }
    return 1;
}

int search_vehicle(const char *reg) {
    for (int i = 0; i < vehicle_count; i++) {
        if (strcmp(vehicles[i].reg, reg) == 0) return 1;
    }
    return 0;
}