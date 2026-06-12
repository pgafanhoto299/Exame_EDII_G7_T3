#include "include/utils/geo.h"
#include <stdio.h>

int main()
{
    Coordenadas cidadela = {-8.8272, 13.2307};
    Coordenadas maculusso = {-8.8150, 13.2350};
    double d = geo_haversine(cidadela, maculusso);
    printf("Distância: %.2f m\n", d);
    printf("A pé: %.2f min\n", geo_tempo_minutos(d, TRANSPORTE_PE));

    return 0;
}