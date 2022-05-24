CC = gcc
NAME = RunnerSDL

OBJ = &(SRC: .c=.o)

CFLAGS += 	-W 	-Wall 	-Wextra -Werror

LIBS += 	-lSDL2 
# -lSDL2_image -lSDL2_ttf -lSDL2_mixer


all		: $(NAME)
$(NAME)	: $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean 	: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY 	:
