

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#define EPS 1e-12

int main(void) {
    double side1 = 0;
    double side2 = 0;
    double side3 = 0;
    char shape;
    char shape2;
    char shapename1[50];
    char shapename2[50];
    double perimeter1 = 0.0;
    double perimeter2 = 0.0;
    double area1 = 0.0;
    double area2 = 0.0;
    double halfperimeter;
    char psymbol = ' ';
    char asymbol = ' ';
    double dif;
    printf("Shape #1\n");
    scanf(" %c",&shape);
    // Finds the first shape
    if(shape == 'S'){
        if(scanf(" %lf", &side1) != 1 || side1 <= 0){
            printf("Invalid input.\n");
            return -1;
        }
        //assigns the name of the shape to shapename
        //and finds the perimeter and area
        strcpy(shapename1, "square #1");
        perimeter1 = side1*4;
        area1 = side1*side1;
    }
    else if (shape == 'R'){
        if(scanf(" %lf %lf", &side1, &side2) != 2 || side1 <= 0 || side2 <= 0 || fabs(side1-side2) < EPS * side2){
            printf("Invalid input.\n");
            return -1;
        }
        strcpy(shapename1, "rectangle #1");
        perimeter1 = side1*2 + side2*2;
        area1 = side1 * side2;
    }
    else if (shape == 'T'){
        if(scanf(" %lf %lf %lf", &side1, &side2, &side3) != 3 || side1 <= 0 || side2 <= 0 || side3 <= 0 ){
            printf("Invalid input.\n");
            return -1;
        }
        //Checks if one side is greater than the sum of other two sides
        if(side1 > side3){
            double tmp = side1;
            side1 = side3;
            side3 = tmp;
            
        }
        if(side2 > side3){
            double tmp = side2;
            side2 = side3;
            side3 = tmp;
        }
        dif = fabs(side3 - (side1+side2));
        if(dif <= 100*EPS*dif){
            printf("Invalid input.\n");
            return -1;
        }
        //Finds the perimeter and area of the first shape
        strcpy(shapename1, "triangle #1");
        perimeter1 = side1+side2+side3;
        halfperimeter = perimeter1/2;
        area1 = sqrt( halfperimeter*(halfperimeter-side1)*(halfperimeter-side2)*(halfperimeter-side3));
        
    }
    else{
        printf("Invalid input.\n");
        return -1;
    }
    //Does the same things for the second shape
    printf("Shape #2\n");
    scanf(" %c", &shape2);
    
    
    
    if(shape2 == 'S'){
        if(scanf(" %lf", &side1) != 1 || side1 <= 0){
            printf("Invalid input.\n");
            return -1;
        }
        strcpy(shapename2, "square #2");
        perimeter2 = side1*4;
        area2 = side1*side1;
    }
    else if (shape2 == 'R'){
        if(scanf(" %lf %lf", &side1, &side2) != 2 || side1 <= 0 || side2 <= 0 || fabs(side1 -side2) < side2 * EPS){
            printf("Invalid input.\n");
            return -1;
        }
        strcpy(shapename2, "rectangle #2");
        perimeter2 = side1*2 + side2*2;
        area2 = side1 * side2;
        
    }
    else if (shape2 == 'T'){
        if(scanf(" %lf %lf %lf", &side1, &side2, &side3) != 3 || side1 <= 0 || side2 <= 0 || side3 <= 0 ){
            printf("Invalid input.\n");
            return -1;
        }
        if(side1 > side3){
            double tmp = side1;
            side1 = side3;
            side3 = tmp;
            
        }
        if(side2 > side3){
            double tmp = side2;
            side2 = side3;
            side3 = tmp;
        }
        dif = fabs(side3 - (side1+side2));
        if(fabs(side1+side2-side3)<side3 * EPS || side1+side2 < side3){
            printf("Invalid input.\n");
            return -1;
        }

        strcpy(shapename2, "triangle #2");
        perimeter2 = side1+side2+side3;
        halfperimeter = perimeter2/2;
        area2 = sqrt( halfperimeter*(halfperimeter-side1)*(halfperimeter-side2)*(halfperimeter-side3));
        
    }
    
    dif = EPS;
    //Finds which perimeter and area is greater
    double perdif = fabs(perimeter1-perimeter2);
    if ( fabs(perdif-dif) < dif * EPS || fabs(perimeter1 - perimeter2 ) < perimeter2 * EPS){
        psymbol = '=';
    }

    else if(perimeter1 > perimeter2){
        psymbol = '>';
    }

    else if(perimeter1 < perimeter2){
        psymbol = '<';
    }
    perdif = fabs(area1-area2);
    if( fabs(perdif-dif) < dif * EPS || fabs(area1-area2) < EPS * area2){
        asymbol = '=';
    }
    else if(area1 > area2){
        asymbol = '>';
    }

    else if(area1 < area2){
        asymbol = '<';
    }
    printf("Perimeter: %s %c %s\n", shapename1, psymbol, shapename2);
    
    printf("Area: %s %c %s\n", shapename1, asymbol, shapename2);
    
    return 0;
}
