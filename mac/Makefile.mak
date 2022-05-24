



OBJ		=		$(SRC:.c=.o)

CFLAGS	+=		-I./include/SDL/
CFLAGS	+=		-W -Werror -Wall -Wextra

LIBS	+=		-lSDL2 -lSDl_image -lSDL2ttf 

all:			$(NAME)

$(NAME):		$(OBJ)
	$(CC)	$(OBJ)	$(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f	$(NAME)
