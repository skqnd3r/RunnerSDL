CC = clang
NAME = RunnerSDL

SRC = source/main.c\
	source/collider.c\
	source/draw.c\
	source/init.c\
	source/input.c\
	source/entity.c\

OBJ = $(SRC:.c=.o)

CFLAGS += -I /opt/homebrew/include -I include  #ajout
CFLAGS += -W -Wall -Wextra -Werror

LIBS += -l SDL2 -l SDL2_image -L/opt/homebrew/lib #ajout 

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re