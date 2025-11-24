#ifndef VEHICLE_H
#define VEHICLE_H

#define MAX_REG 20
#define MAX_OWNER 40
#define MAX_VTYPE 20

typedef struct {
    char reg[MAX_REG];
    char owner[MAX_OWNER];
    char vtype[MAX_VTYPE];
} Vehicle;

/* Simple vehicle functions */
int add_vehicle(void);
int list_vehicles(void);
int search_vehicle(const char *reg);

#endif /* VEHICLE_H */