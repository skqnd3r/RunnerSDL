CC = gcc
NAME = RunnerSDL
SRC = source/main.c\
	source/collider.c\
	source/draw.c\
	source/init.c\
	source/input.c\
	source/entity.c\

OBJ = $(SRC:.c=.o)

CFLAGS += -I./include
CFLAGS += -W -Wall -Wextra -Werror

# LFLAGS += -L ./SDL2.framework/Versions/Current ./SDL2_image.framework/Versions/Current
# FFLAGS += -F . -framework SDL2 -I SDL2.framework/Headers -framework SDL2_image -I SDL2_image.framework/Headers

LIBS += -lSDL2 -lSDL2_image
# -lSDL2_ttf -lSDL2_mixer


all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re