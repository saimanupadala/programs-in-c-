#include <stdio.h>

struct Salary {
    float basic;
    float hra;
    float da;
};

union EmploymentType {
    int pf_number;       
    int contract_duration;  
};

struct Employee {
    int id;
    char name[50];
    struct Salary salary;
    union EmploymentType empType;
    char type;   
};
