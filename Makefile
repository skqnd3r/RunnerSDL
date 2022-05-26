CC = gcc
NAME = RunnerSDL
SRC = source/main.c\
	source/draw.c\
	source/init.c\
	source/input.c\

OBJ = $(SRC:.c=.o)

CFLAGS += -I./include
CFLAGS += -W -Wall -Wextra -Werror

LIBS += -lSDL2 -lSDL2_image
# -lSDL2_ttf -lSDL2_mixer


all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY	: all clean fclean re