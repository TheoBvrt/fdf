NAME = fdf
SRCS = ./srcs/main.c \
		./srcs/parser/map_parser.c \
		./srcs/parser/color_parser.c \
		./srcs/parser/data_parser.c \
		./srcs/parser/parser_utils.c \
		./srcs/data_formats/data_format.c \
		./srcs/data_formats/data_format_2.c \
		./srcs/color/color_scheme.c \
		./srcs/color/color_manager.c \
		./srcs/rendering/events/mlx_events.c \
		./srcs/rendering/interface/button.c \
		./srcs/rendering/interface/display_string.c \
		./srcs/rendering/interface/interface.c \
		./srcs/rendering/projections.c \
		./srcs/rendering/put_pixel.c \
		./srcs/rendering/render.c \
		./srcs/rendering/matrix.c \
		./srcs/utils/error.c \
		./srcs/utils/exit.c \
		./srcs/utils/free_tab.c \
		./srcs/utils/utils.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Iheaders -Imlx -Wall -Werror -Wextra -g

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