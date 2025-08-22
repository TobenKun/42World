CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INC_H = libft.h
BONUS = ft_atoi.c        \
ft_bzero.c               \
ft_calloc.c              \
ft_isalnum.c             \
ft_isalpha.c             \
ft_isascii.c             \
ft_isdigit.c             \
ft_isprint.c             \
ft_itoa.c                \
ft_lstadd_back_bonus.c   \
ft_lstadd_front_bonus.c  \
ft_lstclear_bonus.c      \
ft_lstdelone_bonus.c     \
ft_lstiter_bonus.c       \
ft_lstlast_bonus.c       \
ft_lstmap_bonus.c        \
ft_lstnew_bonus.c        \
ft_lstsize_bonus.c       \
ft_memchr.c              \
ft_memcmp.c              \
ft_memcpy.c              \
ft_memmove.c             \
ft_memset.c              \
ft_putchar_fd.c          \
ft_putendl_fd.c          \
ft_putnbr_fd.c           \
ft_putstr_fd.c           \
ft_split.c               \
ft_strchr.c              \
ft_strdup.c              \
ft_striteri.c            \
ft_strjoin.c             \
ft_strlcat.c             \
ft_strlcpy.c             \
ft_strlen.c              \
ft_strmapi.c             \
ft_strncmp.c             \
ft_strnstr.c             \
ft_strrchr.c             \
ft_strtrim.c             \
ft_substr.c              \
ft_tolower.c             \
ft_toupper.c

SOURCES = ft_atoi.c        \
ft_bzero.c                 \
ft_calloc.c                \
ft_isalnum.c               \
ft_isalpha.c               \
ft_isascii.c               \
ft_isdigit.c               \
ft_isprint.c               \
ft_itoa.c                  \
ft_memchr.c                \
ft_memcmp.c                \
ft_memcpy.c                \
ft_memmove.c               \
ft_memset.c                \
ft_putchar_fd.c            \
ft_putendl_fd.c            \
ft_putnbr_fd.c             \
ft_putstr_fd.c             \
ft_split.c                 \
ft_strchr.c                \
ft_strdup.c                \
ft_striteri.c              \
ft_strjoin.c               \
ft_strlcat.c               \
ft_strlcpy.c               \
ft_strlen.c                \
ft_strmapi.c               \
ft_strncmp.c               \
ft_strnstr.c               \
ft_strrchr.c               \
ft_strtrim.c               \
ft_substr.c                \
ft_tolower.c               \
ft_toupper.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : make_mandatory

$(NAME) : make_mandatory

bonus : make_bonus

make_bonus : $(BONUS_OBJ)
	ar cr $(NAME) $^
	touch $@

make_mandatory : $(OBJECTS)
	ar cr $(NAME) $^
	touch $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_H)

clean :
	rm -f $(BONUS_OBJ)
	rm -f make_bonus make_mandatory

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
