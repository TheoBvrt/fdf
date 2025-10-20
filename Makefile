NAME = fractol
SRCS = ./srcs/main.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Iheaders -Imlx 

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