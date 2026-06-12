#ifndef KILAFIELD_GEO_H
#define KILAFIELD_GEO_H

/* ======================= */
/* geo.h - Utilitarios geoespaciais */
/* Fórmula de Haversine para distância entre coordenadas */
/* Cálculo de tempo de deslocação por modalidade */
/* ======================= */

#include "../core/types.h"

/* Distância em metros entre 2 pontos geográficos */
double geo_haversine(Coordenadas a, Coordenadas b);

/* Tempo de deslocação em minutos dado a distância e velocidade*/
double geo_tempo_minutos(double distancia_m, TipoTransporte transporte);

/* Preenche os campos de tempo num ResultadoPesquisa */
void geo_preencher_tempos(ResultadoPesquisa *r);

/* Verifica se coordenadas estão no domínio de Angola*/
int geo_coordenadas_validas(Coordenadas c);

#endif