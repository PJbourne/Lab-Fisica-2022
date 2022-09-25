#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double D = 0.028, P_l[4] = {0.56,0.5,0.42,0.36}, P = 0.62, g=0, ug=0, E=0, uE, p = 0, up = 0, m = 0.0628, um = 0.0019, A=0, uA=0;
    double uV[4], V[4], h[4] = {0.014,0.028,0.0425,0.057}, h_prof[4] = {0.013,0.026,0.039,0.052}, u_prof = 0.001;
    double u = 0.0005, ros[4], uros[4];
    g = P/m;
    ug = sqrt(pow((0.01/0.0628),2.0) + pow(((0.62*0.0019)/(0.0628*0.0628)),2.0));
    printf("Gravidade   = %f\n",g);
    printf("Incerteza g = %f\n",ug);

    uA = sqrt(pow((0.01/0.0628)*u,2.0));
    A = M_PI * pow((D/2),2.0);

    printf("Area      = %f\n",A);
    printf("Incerteza A = %f\n",uA);

    for(int i = 0;i<4;i++){
        uV[i] = sqrt( pow( (((pow(D,2.0)) * M_PI * u )/4) , 2.0) + pow( ( (2 * D * M_PI * u * h[i])/4) , 2.0) );
        printf("u(V) (h(%f)) = %f",h[i],uV[i] * 1000000000);
        printf("\n");
    }
    printf("\n");
    for(int i = 0;i<4;i++){
        V[i] = (((D/2)*(D/2))*M_PI)*h[i];
        printf("V (h(%f)) = %f",h[i],V[i] * 1000000000);
        printf("\n");
    }
    printf("\n");
    uE = sqrt( pow(0.01,2.0) + pow(0.01,2.0) );
    for(int i=0;i<4;i++){
        E = P - P_l[i];
        p = E/(g*V[i]);
        up = sqrt( pow(( uE/V[i] ),2.0) + pow(( (E*uV[i])/(V[i]*V[i]) ),2.0));
        printf("p (h(%f)) = %f",h[i],p/1000);
        ros[i] = p;
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<4;i++){
        E = P - P_l[i];
        p = E/(g*V[i]);
        up = sqrt( pow(( uE/V[i] ),2.0) + pow(( (E*uV[i])/(V[i]*V[i]) ),2.0));
        printf("up (h(%f)) = %f",h[i],up/10000);
        uros[i] = up;
        printf("\n");
    }
    for(int i=0;i<4;i++){
        printf("Densidade min: %f e max: %f", ros[i]/1000 - uros[i]/10000, ros[i]/1000 + uros[i]/10000);
        printf("\n");
    }
    printf("\n\n-------------------------------------------------\nAbaixo, calculos com valores fornecidos\n\n");

    for(int i = 0;i<4;i++){
        uV[i] = sqrt( pow( (((pow(D,2.0)) * M_PI * u_prof )/4) , 2.0) + pow( ( (2 * D * M_PI * u_prof * h_prof[i])/4) , 2.0) );
        printf("u(V) (h(%f)) = %f",h_prof[i],uV[i] * 1000000000);
        printf("\n");
    }
    printf("\n");
    for(int i = 0;i<4;i++){
        V[i] = (((D/2)*(D/2))*M_PI)*h_prof[i];
        printf("V (h(%f)) = %f",h_prof[i],V[i] * 1000000000);
        printf("\n");
    }
    printf("\n");
    uE = sqrt( pow(0.01,2.0) + pow(0.01,2.0) );
    for(int i=0;i<4;i++){
        E = P - P_l[i];
        p = E/(g*V[i]);
        up = sqrt( pow(( uE/V[i] ),2.0) + pow(( (E*uV[i])/(V[i]*V[i]) ),2.0));
        printf("p (h(%f)) = %f",h_prof[i],p);
        ros[i] = p;
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<4;i++){
        E = P - P_l[i];
        p = E/(g*V[i]);
        up = sqrt( pow(( uE/V[i] ),2.0) + pow(( (E*uV[i])/(V[i]*V[i]) ),2.0));
        printf("up (h(%f)) = %f",h_prof[i],up);
        uros[i] = up;
        printf("\n");
    }
    for(int i=0;i<4;i++){
        printf("Densidade min: %f e max: %f", ros[i] - uros[i], ros[i] + uros[i]);
        printf("\n");
    }
}
