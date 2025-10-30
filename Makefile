NAME = fdf
SRCS = ./srcs/main.c ./srcs/parser/error.c ./srcs/parser/map_parser.c ./srcs/utils/free_tab.c ./srcs/rendering/put_pixel.c \
./srcs/rendering/render.c ./srcs/rendering/matrix.c ./srcs/rendering/mlx_events.c ./srcs/parser/color_parser.c ./srcs/rendering/projections.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Iheaders -Imlx -g

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	${MAKE} -C ./libft 
	$(CC) $(OBJS) ./libft/libft.a -Lmlx -lmlx -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS} 
	make clean -C ./libft

fclean: clean
	${RM} ${NAME}
	make fclean -C ./libft

re: fclean all