CC = gcc
NAME = RunnerSDL

SRC = source/main.c\
	source/event.c\
	source/collider.c\
	source/draw.c\
	source/init.c\
	source/input.c\
	source/entity.c\

OBJ = $(SRC:.c=.o)

CFLAGS += -I./include
CFLAGS += -W -Wall -Wextra -Werror

LIBS += -lSDL2 -lSDL2_image

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re