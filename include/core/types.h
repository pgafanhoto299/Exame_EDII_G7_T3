#ifndef KILAFIELD_TYPES_H
#define KILAFIELD_TYPES_H

/* ======================= */
/* types.h - Definições centrais de tipos e constantes*/
/* KilaField | Estruturas de Dados */
/* ======================= */

#include <stdint.h>
#include <time.h>

/* Limites do sistema */
#define MAX_CAMPOS 256
#define MAX_JOGADORES 512
#define MAX_RESERVAS 4096
#define MAX_NOME 128
#define MAX_ID 16
#define MAX_HORARIO 6 /* "HH:MM:\0" */
#define MAX_ARESTAS (MAX_CAMPOS * MAX_CAMPOS)
#define MAX_LINHA_FICHEIRO 512

/* --- Velocidades de deslocação (km/h) ----- */
#define VEL_PE 5.0
#define VEL_TAXI 40.0
#define VEL_AUTOCARRO 20.0

/* --- Raio médio da terra (metros) ---------- */
#define RAIO_TERRA_M 6371000.0

typedef enum
{
    KF_OK = 0,
    KF_ERR_FICHEIRO = -1,
    KF_ERR_FORMATO = -2,
    KF_ERR_DUPLICADO = -3,
    KF_ERR_NAO_ENCONTRADO = -4,
    KF_ERR_RESERVADO = -5,
    KF_ERR_MEMORIA = -6,
    KF_ERR_INVALIDO = -7
} Kfstatus;

/* --- Modalidade de transporte -------------- */
typedef enum
{
    TRANSPORTE_PE = 0,
    TRANSPORTE_TAXI = 1,
    TRANSPORTE_AUTOCARRO = 2
} TipoTransporte;

/* --- Coordenadas geográficas --------------- */
typedef struct
{
    double latitude;
    double longitude;
} Coordenadas;

/* --- Horário de funcionamento -------------- */
typedef struct
{
    int hora_abertura; /* 0-23*/
    int min_abertura;
    int hora_fecho;
    int min_fecho;
} Horario;

/* --- Campo desportivo ----------------------- */
typedef struct
{
    char id[MAX_ID];
    char nome[MAX_NOME];
    Coordenadas coordenadas;
    Horario horario;
    int capacidade;
    int indice_grafo; /* ínidce do vértice no grafo */
} Campo;

/* --- Jogador -------------------------------- */
typedef struct
{
    char id[MAX_ID];
    char nome[MAX_NOME];
    Coordenadas coordenadas;
} Jogador;

/* --- Reserva -------------------------------- */
typedef struct
{
    char id_campo[MAX_ID];
    char id_jogador[MAX_ID];
    int ano;
    int mes;
    int dia;
    int hora_inicio;
    int min_inicio;
    int hora_fim;
    int min_fim;
} Reserva;

/* --- Resultado de pesquisa de campo próximo -- */
typedef struct
{
    Campo *campo;
    double distancia_m;
    double tempo_pe_min;
    double tempo_taxi_min;
    double tempo_autocarro_min;
    int disponivel;
} ResultadoPesquisa;

#endif
