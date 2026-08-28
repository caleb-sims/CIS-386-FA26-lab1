#include <stdio.h>
#include <math.h>

double area(double a, double b, double c) {
    double s = (a+b+c)/2;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    
    return area;
}

int main(void) {
    double a, b, c;
    printf("Enter side 1: ");
    scanf("%lf", &a);
    printf("Enter side 2: ");
    scanf("%lf", &b);
    printf("Enter side 3: ");
    scanf("%lf", &c);

    // Check if triangle is impossible
    if (a >= b + c || b >= a + c || c >= a + b){
        printf("impossible\n");
        return 0;
    }

    int ab_equal = (a==b);
    int bc_equal = (b==c);
    int ac_equal = (a==c);

    if (ab_equal && bc_equal) {
        printf("equilateral\nisosceles\n");
    } else if (ab_equal || bc_equal || ac_equal) {
        printf("isosceles\n");
    } else {
        printf("scalene\n");
    }

    printf("area: %.2lf\n", area(a,b,c));

    return 0;
}

