NAME		=	pipex
NAME_B		=	pipex_b

SRCS_FILES	= 	pipex.c \
				utils.c \
				raise_error.c

SRCS_B_FILES	= 	pipex_bonus.c \
					utils_bonus.c \
					raise_error.c \
					redirects_bonuc.c

SRCS_FOLDER	=	source/

SRCS		= 	$(addprefix $(SRCS_FOLDER),$(SRCS_FILES))
SRCS_B		= 	$(addprefix $(SRCS_FOLDER),$(SRCS_B_FILES))
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

INCLUDE		=	-I./include -I./libs/libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD
RM			=	rm -f

LIB = ./libs/libft/libft.a

all:		$(NAME)

bonus:		$(NAME_B)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@
		
$(NAME):	$(OBJS)
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) $(LIB) -o $(NAME) $(OBJS)

$(NAME_B):	$(OBJS_B)
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) $(LIB) -o $(NAME_B) $(OBJS_B)

clean:
			$(RM) $(OBJS) $(OBJS:.o=.d) $(OBJS_B) $(OBJS_B:.o=.d)
			@make -C $(dir $(LIB)) clean

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			$(RM) $(NAME)
			$(RM) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re bonus
-include	$(OBJS:.o=.d)
-include	$(OBJS_B:.o=.d)
