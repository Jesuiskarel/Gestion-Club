CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS = 
SRC = main.c membre.c taches.c ressource.c finance.c
OBJ = $(SRC:.c=.o)
EXEC = projet_club_app

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(EXEC)
