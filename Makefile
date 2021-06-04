NAME		=	pipex
NAME_B		=	checker

SRCS_FILES	= 	pipex.c \
				raise_error.c 

SRCS_B_F	=	 

SRCS_FOLDER	=	source/
SRCS_B_FLD	=	source_bonus/
HEADER		=	include/push_swap.h

SRCS		= 	$(addprefix $(SRCS_FOLDER),$(SRCS_FILES))
SRCS_B		=	$(addprefix $(SRCS_B_FLD),$(SRCS_B_F))
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
			$(RM) $(OBJS) $(OBJS:.o=.d)
			$(RM) $(OBJS_B) $(OBJS_B:.o=.d)
			@make -C $(dir $(LIB)) clean

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			$(RM) $(NAME)
			$(RM) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re bonus
-include	$(OBJS:.o=.d)
-include	$(OBJS_B:.o=.d)