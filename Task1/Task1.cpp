#include <stdio.h>

int main() {
    float Ax, Ay, Bx, By, Cx, Cy;
    printf("Enter dots' coordinates\nA = ");
    scanf("%f%f", &Ax, &Ay);
    printf("B = ");
    scanf("%f%f", &Bx, &By);
    printf("C = ");
    scanf("%f%f", &Cx, &Cy);
    float ABx = Bx - Ax, ABy = By - Ay,
        ACx = Cx - Ax, ACy = Cy - Ay,
        BCx = Cx - Bx, BCy = Cy - By;
    float AB_0 = Ay * ABx - Ax * ABy,
        AC_0 = Ay * ACx - Ax * ACy,
        BC_0 = By * BCx - Bx * BCy;
    float AB_C = (Ay - Cy) * ABx + (Cx - Ax) * ABy,
        AC_B = (Ay - By) * ACx + (Bx - Ax) * ACy,
        BC_A = (By - Ay) * BCx + (Ax - Bx) * BCy;
    if ((AB_C * AB_0 > 0) && (AC_B * AC_0 > 0) && (BC_A * BC_0 > 0)) printf("Inside");
    else if ((AB_0 == 0) || (AC_0 == 0) || (BC_0 == 0)) printf("On line");
    else printf("Outside");
    return 0;
}