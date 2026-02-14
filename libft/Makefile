CC := cc
CFLAGS := -Wall -Wextra -Werror

NAME := libft.a

STDLIB := stdlib/ft_atoi.c stdlib/ft_calloc.c stdlib/ft_itoa.c stdlib/free_array.c stdlib/ft_free.c

CTYPE := ctype/ft_isalpha.c ctype/ft_isdigit.c ctype/ft_toupper.c ctype/ft_isalnum.c \
		 ctype/ft_isascii.c ctype/ft_isprint.c ctype/ft_tolower.c 

MEM := mem/ft_memchr.c mem/ft_memcpy.c mem/ft_memset.c mem/ft_bzero.c mem/ft_memcmp.c mem/ft_memmove.c 

STRING := string/ft_strdup.c string/ft_strlcpy.c string/ft_strncmp.c \
		  string/ft_strchr.c string/ft_strrchr.c string/ft_strlcat.c string/ft_strlen.c \
		  string/ft_strnstr.c string/ft_substr.c string/ft_strjoin.c string/ft_strtrim.c string/ft_split.c \
		  string/ft_strmapi.c string/ft_striteri.c string/string.c string/stringlist.c \
		  string/string_append.c string/string_split.c string/string_substr.c

PUT := put/ft_putchar_fd.c put/ft_putstr_fd.c put/ft_putendl_fd.c put/ft_putnbr_fd.c \

LIST := list/ft_lstnew.c list/ft_lstadd_front.c list/ft_lstsize.c list/ft_lstlast.c list/ft_lstadd_back.c \
		list/ft_lstdelone.c list/ft_lstclear.c list/ft_lstiter.c list/ft_lstmap.c

GNL := gnl/get_next_line.c

PRINTF := ft_printf/char_str_handlers.c ft_printf/format_parser.c ft_printf/ft_itoa.c \
		  ft_printf/ft_printf.c ft_printf/ft_itoa_base.c ft_printf/numeric_handlers.c \
		  ft_printf/printing.c

MISC := misc/pow.c

SRC := $(STDLIB) $(CTYPE) $(MEM) $(STRING) $(PUT) $(LIST) $(GNL) $(PRINTF) $(MISC)

OBJDIR := obj

OBJ := $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
DEPS := $(patsubst %.c, $(OBJDIR)/%.d, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

-include $(DEPS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -MMD -MP $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

compile_commands:
	bear -- $(MAKE) re

.PHONY: all clean fclean re
