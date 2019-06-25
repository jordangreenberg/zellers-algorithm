#include <stdio.h>

//Gets the input from user
void inputDate(int *day, int *month, int *year) {
    printf("Please enter a date: ");
    scanf("%d/%d/%d", day, month, year);
}

//Calculates day of week and prints it
void calculateDay(int day, int month, int year) {
    int const MonthAdjustment = 2, YearsInCentury = 100, NumMonths = 12, NumDays = 7;
    
    //Define the integer variables needed for algorithm
    int a = month - MonthAdjustment; //March has value 1
    int b = day;
    int c = year % YearsInCentury;
    int d = year / YearsInCentury;
    
    //if a is <= 0 (month is January or February), make 11 or 12 respectivley, and subtract 1 from year
    if (a <= 0) {
        a += NumMonths;
        c--;
        
        //Ensure c is not negative, subtract a century if so
        if (c < 0) {
            c += YearsInCentury;
            d--;
        }
    }
    
    //Compute the next 5 integer values according to algorithm
    int w = (13 * a - 1) / 5;
    int x = c / 4;
    int y = d / 4;
    int z = w + x + y + b + c - (2 * d);
    int r = z % 7;
    
    //Ensure r is not negative, if so add 7 days
    if (r < 0) {
        r += NumDays;
    }
    
    //Output results
    printf("The day %d/%d/%d is a ", day, month, year);
    
    //Determine day and print
    switch (r) {
        case (0) :
            printf("Sunday");
            break;
        case (1) :
            printf("Monday");
            break;
        case (2) :
            printf("Tuesday");
            break;
        case (3) :
            printf("Wednesday");
            break;
        case (4) :
            printf("Thursday");
            break;
        case (5) :
            printf("Friday");
            break;
        case (6) :
            printf("Saturday");
            break;
    }
    printf(".\n");
}

/**
int main(int argc, char **argv) {
    int day = 0, month = 0, year = 0;
    
    inputDate(&day, &month, &year);
    calculateDay(day, month, year);
}
*/