/* ============================================================
 * geo.c — Utilitários geoespaciais
 *
 * Fórmula de Haversine:
 *   (a = \sin^2\left(\frac{\Delta\phi}{2}\right) + \cos(\phi_1) \cdot \cos(\phi_2) \cdot \sin^2\left(\frac{\Delta\lambda}{2}\right)\)\(c = 2 \cdot \text{atan2}\left(\sqrt{a}, \sqrt{1-a}\right)\)d = R ⋅ c
 *   onde R = 6 371 000 m
 * ============================================================ */

#include "../../include/utils/geo.h"
#include <math.h>
#include <stdio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define DEG2RAD(d) ((d) * M_PI / 180.0)

/* --- Haversine */
double geo_haversine(Coordenadas a, Coordenadas b)
{
    double lat1 = DEG2RAD(a.latitude);
    double lat2 = DEG2RAD(b.latitude);
    double dlat = DEG2RAD(b.latitude - a.latitude);
    double dlon = DEG2RAD(b.longitude - a.longitude);

    double h = sin(dlat / 2.0) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2.0) * sin(dlon / 2.0);

    double c = 2.0 * asin(sqrt(h));
    return RAIO_TERRA_M * c; /* metros */
}

/* ── Tempo de deslocação ─────────────────────────────────── */
double geo_tempo_minutos(double distancia_m, TipoTransporte transporte) {
    double velocidade_kmh;
    switch (transporte) {
        case TRANSPORTE_PE:        velocidade_kmh = VEL_PE;        break;
        case TRANSPORTE_TAXI:      velocidade_kmh = VEL_TAXI;      break;
        case TRANSPORTE_AUTOCARRO: velocidade_kmh = VEL_AUTOCARRO; break;
        default:                   velocidade_kmh = VEL_PE;
    }
    /* dist(km) / vel(km/h) * 60 min/h */
    double dist_km = distancia_m / 1000.0;
    return (dist_km / velocidade_kmh) * 60.0;
}

/* --- Preencher tempos num resultado -----------*/
void geo_preencher_tempos(ResultadoPesquisa *r)
{
    r->tempo_pe_min = geo_tempo_minutos(r->distancia_m, TRANSPORTE_PE);
    r->tempo_taxi_min = geo_tempo_minutos(r->distancia_m, TRANSPORTE_TAXI);
    r->tempo_autocarro_min = geo_tempo_minutos(r->distancia_m, TRANSPORTE_AUTOCARRO);
}

/* --- Validação de coordenadas (Angola: lat -18 a -4, lon 11 a 25) */
int geo_coordenadas_validas(Coordenadas c)
{
    return (c.latitude >= -18.0 && c.latitude <= -4.0 &&
            c.longitude >= 11.0 && c.longitude <= 25.0);
}