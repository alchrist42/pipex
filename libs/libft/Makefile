NAME		=	libft.a

SRCS		= 	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c \
				ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c \
				ft_itoa.c		ft_memccpy.c	ft_memchr.c		ft_memcmp.c \
				ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_putchar_fd.c \
				ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c \
				ft_strchr.c		ft_strdup.c		ft_strjoin.c	ft_strlcat.c \
				ft_strlcpy.c	ft_strlen.c		ft_strmapi.c	ft_strncmp.c \
				ft_strnstr.c	ft_strrchr.c	ft_strtrim.c	ft_substr.c \
				ft_tolower.c	ft_toupper.c	\
				ft_split_set.c	ft_cnt_ch.c 	ft_atoi_long.c	ft_split_free.c	\
				ft_split_len.c	
			
SRCS_B		=	ft_lstnew.c			ft_lstadd_front.c		ft_lstsize.c \
				ft_lstlast.c 		ft_lstadd_back.c		ft_lstdelone.c \
				ft_lstclear.c		ft_lstiter.c 			ft_lstmap.c \
				ft_lstfind.c		ft_lstsort.c			ft_lstpop.c \
				ft_lstpop_find.c	

HEADER		=	libft.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))


CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBC		=	ar rcs

all:		$(NAME) 

%.o:		%.c
			$(CC) $(CFLAGS) -c -O3 $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(LIBC) $(NAME) $?
			$(MAKE) bonus

bonus:		$(OBJS_B) $(HEADER)
			$(LIBC) $(NAME) $?

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus

