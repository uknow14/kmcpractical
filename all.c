
// 1. Write a program to find s = ut +
// 1
// 2
// at2 using a function.
#include <stdio.h>

float calculate(float u, float t, float a) {
    float s;
    s = u * t + 0.5 * a * t * t;
    return s;
}

int main() {
    float u, t, a, s;
    printf("Enter initial velocity (u): ");
    scanf("%f", &u);
    printf("Enter time (t): ");
    scanf("%f", &t);
    printf("Enter acceleration (a): ");
    scanf("%f", &a);
    s = calculate(u, t, a);
    printf("Distance s = %.2f\n", s);
    return 0;
}
// ============================================

// 2.Write a program to find the average mark of computer science subject of 5 students using a function

#include <stdio.h>

int Average(int marks[]) {
    int i, sum = 0;
    for (i = 0; i < 5; i++) {
        sum = sum + marks[i];
    }
    return sum / 5;
}

int main() {
    int marks[5], i, avg;
    printf("Enter marks of 5 students:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
    avg = Average(marks);
    printf("Average mark = %d\n", avg);
    return 0;
}

// =============================================

// 3. Write a program to find a factorial of a number using a recursive function.

#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n, result;
    printf("Enter a number: ");
    scanf("%d", &n);
    result = factorial(n);
    printf("Factorial of %d = %d\n", n, result);
    return 0;
}
// ================================================

// 4. Write a program to find nth power of a number which the number itself is using a library function. E.g.,
// if a user enters 5, it is 55=3125.

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double result;
    printf("Enter a number: ");
    scanf("%d", &n);
    result = pow(n, n);
    printf("%d^%d = %.0f\n", n, n, result);
    return 0;
}
// =================================================

// 5.Write a program to find diameter, circumference and area of a circle using pointer in a function [the
// prototype of the function should be void Calculate(float, float *, float *, float *)].


#include <stdio.h>

void Calculate(float r, float *d, float *c, float *a) {
    *d = 2 * r;
    *c = 2 * 3.14159 * r;
    *a = 3.14159 * r * r;
}

int main() {
    float r, d, c, a;
    printf("Enter radius: ");
    scanf("%f", &r);
    Calculate(r, &d, &c, &a);
    printf("Diameter      = %.2f\n", d);
    printf("Circumference = %.2f\n", c);
    printf("Area          = %.2f\n", a);
    return 0;
}
// ==================================================

// 6. Write a program to get name, id and mark of computer science subject of 5 students and find the
// average mark using a structure.

#include <stdio.h>

struct Student {
    char name[50];
    int id;
    int mark;
};

int main() {
    struct Student s[5];
    int i, sum = 0;
    float avg;

    for (i = 0; i < 5; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter ID: ");
        scanf("%d", &s[i].id);
        printf("Enter mark: ");
        scanf("%d", &s[i].mark);
        sum = sum + s[i].mark;
    }

    avg = sum / 5.0;
    printf("\nAverage mark = %.2f\n", avg);
    return 0;
}
// =============================================

// 7.Write a program to get name and price of 5 cars and find the name of the most expensive car using a
// structure.

#include <stdio.h>

struct Car {
    char name[50];
    float price;
};

int main() {
    struct Car c[5];
    int i, maxIndex = 0;

    for (i = 0; i < 5; i++) {
        printf("Enter name of car %d: ", i + 1);
        scanf("%s", c[i].name);
        printf("Enter price: ");
        scanf("%f", &c[i].price);
    }

    for (i = 1; i < 5; i++) {
        if (c[i].price > c[maxIndex].price) {
            maxIndex = i;
        }
    }

    printf("\nMost expensive car: %s (Rs. %.2f)\n", c[maxIndex].name, c[maxIndex].price);
    return 0;
}
// ===================================================

// 8.Write a program to get name, contact and salary of 5 staffs and store them in a file.
#include <stdio.h>

struct Staff {
    char name[50];
    char contact[15];
    float salary;
};

int main() {
    struct Staff s[5];
    int i;
    FILE *fp;

    fp = fopen("staff.txt", "w");
    if (fp == NULL) {
        printf("File error");
        return 1;
    }

    for (i = 0; i < 5; i++) {
        printf("Enter name of staff %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter contact: ");
        scanf("%s", s[i].contact);
        printf("Enter salary: ");
        scanf("%f", &s[i].salary);
        fprintf(fp, "%s %s %.2f\n", s[i].name, s[i].contact, s[i].salary);
    }

    fclose(fp);
    printf("Data saved successfully!\n");
    return 0;
}
// =======================================================================

// 9. Let’s say name, contact and salary of staffs are stored in a file (we don’t know how many records are
// in a file). Display data of all staffs who earn more than Rs. 20,000.

#include <stdio.h>

struct Staff {
    char name[50];
    char contact[15];
    float salary;
};

int main() {
    struct Staff s;
    FILE *fp;

    fp = fopen("staff.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    printf("Staffs earning more than Rs. 20000:\n");
    while (fscanf(fp, "%s %s %f", s.name, s.contact, &s.salary) != EOF) {
        if (s.salary > 20000) {
            printf("Name: %s | Contact: %s | Salary: %.2f\n", s.name, s.contact, s.salary);
        }
    }

    fclose(fp);
    return 0;
}