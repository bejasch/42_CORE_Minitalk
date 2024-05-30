NAME = libft.a
HEADER = libft.h
SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isai.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c\
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c\
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
ft_pf_putchar.c ft_pf_puthex.c ft_pf_putint.c ft_pf_putptr.c ft_pf_putstr.c\
ft_pf_putunsigned.c ft_printf.c\
get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
BONUS_SOURCES = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c\
ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c\
ft_lstnew_bonus.c ft_lstsize_bonus.c
BONUSES = $(BONUS_SOURCES:.c=.o)
FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

.c.o:
	cc $(FLAGS) -c $< -o $@

$(NAME):	$(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus:	$(OBJECTS) $(BONUSES)
	ar -rc $(NAME) $(OBJECTS) $(BONUSES)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)
	rm -f $(BONUSES)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	clean fclean all re bonus
