CC = GCC

NAME = minitalk

CFLAGS = -Wall -Wextra -Werror

INCLUDES = minitalk.h

SERVER = server

CLIENT = client

SERVER_SRC = server.c

CLIENT_SRC = client.c

SERVER_BONUS_SRC = server_bonus.c

CLIENT_BONUS_SRC = client_bonus.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

RM = rm -f

all: $(NAME)

client: $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT)

server: $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER)

$(NAME) : $(SERVER) $(CLIENT)

bonus: $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -o $(CLIENT)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -o $(SERVER)

clean:
	$(RM) $(SERVER_OBJ) $(SERVER_BONUS_OBJ)
	$(RM) $(CLIENT_OBJ) $(CLIENT_BONUS_OBJ)

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: fclean all

.PHONY: all clean fclean bonus re client server
