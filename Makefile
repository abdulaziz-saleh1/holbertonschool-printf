CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = _printf.c \
      handle_specifier.c \
      buffer_utils.c \
      print_char.c \
      print_string.c \
      print_percent.c \
      print_int_buffer.c \
      print_binary_buffer.c \
      print_unsigned_buffer.c
OBJ = $(SRC:.c=.o)
NAME = libprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
