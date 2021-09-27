PROGRAMAS		= cliente servidor ejercicio2
CC := gcc 
CFLAGS := -O2 -g -D_GNU_SOURCE -Wall -std=gnu99 -pedantic 

# Que no los interprete como ficheros destino
.PHONY:         all clean

# Por defecto
all:            $(PROGRAMAS)

# Borramos todo 
clean:
	rm -f  $(PROGRAMAS)

ejercicio2 : ejercicio2.c 
	$(CC) $(CFLAGS) $^ -o $@

cliente : cliente.c 
	$(CC) $(CFLAGS)  $^ -o $@

servidor : servidor.c 
	$(CC) $(CFLAGS)  $^ -o $@

