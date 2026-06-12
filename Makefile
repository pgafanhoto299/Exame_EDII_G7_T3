# ========================================== #
# Makefile - KilaField			     #
# ========================================== #

CC	= gcc
CFLAGS	= -Wall -Wrextra -stdc=c11 -g -02
LDFLAGS = -lm

TARGET	= kilafield

# Todos os ficheiros .c
SRCS = main.c \
       src/core/grafo.c   \
       src/core/sistema.c \
       src/adt/hashmap.c  \
       src/adt/minheap.c  \
       src/adt/fila.c	  \
       src/io/parser.c	  \
       src/utils/geo.c	  \
       src/ui/ui.c
       
OBJS = $(SRCS:.c=.o

# -- Targets--------------------------------- #

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
    @echo "Build concluído: ./$(TARGET)"

%.0: %.c
    $(CC) $(CFLAGS) -c $< -o $@
    
clean:
    find . -name "*.o" -delete
    rm -f $(TARGET)
    @echo "Limpeza concluída"
    
run: $(TARGET)
    ./$(TARGET)
    
# --Testes básicos ---------------------------- #

test: $(TARGET)
   @echo "=== Teste 1: carregamento do mapa ==="
   echo "0" | ./$(TARGET) data/mapa.txt data/reservas_test.txt
   @echo "=== Testes concluídos ==="
   
   
.PHONY: all clean run test
