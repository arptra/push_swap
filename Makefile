#Compiler Options
C_FLAGS = -Wall -Wextra -Werror
#Filenames
LIBFT_DIR := libft/
NAME_PUSH_SWAP := push_swap
NAME_CHECKER := checker
PUSH_SWAP := push_swap.c  simplelogic.c midpoint.c sortinstr.c simplelogic3.c revrot.c simplelogic2.c sortinstr2.c

CHECKER := checker.c visualisation.c

UTILS := stack_utils.c stack_utils2.c instruction.c instruction2.c fillstack.c comparefunc.c

OBJECTS_PUSH_SWAP := $(PUSH_SWAP:.c=.o)
OBJECTS_CHECKER := $(CHECKER:.c=.o)
OBJECTS_UTILS := $(UTILS:.c=.o)
HEADER = push_swap.h

all: $(NAME_PUSH_SWAP)
$(NAME_PUSH_SWAP): $(OBJECTS_PUSH_SWAP) $(OBJECTS_UTILS)
	make -C $(LIBFT_DIR)
	gcc -o $(NAME_PUSH_SWAP) $(OBJECTS_PUSH_SWAP) $(OBJECTS_UTILS) -L$(LIBFT_DIR) -lft
$(OBJECTS_PUSH_SWAP) $(OBJECTS_UTILS): %.o: %.c
	gcc $(C_FLAGS) -o $@ -c $<

all: $(NAME_CHECKER)
$(NAME_CHECKER): $(OBJECTS_CHECKER) $(OBJECTS_UTILS)
	gcc -o $(NAME_CHECKER) $(OBJECTS_CHECKER) $(OBJECTS_UTILS) -L$(LIBFT_DIR) -lft
$(OBJECTS_CHECKER): %.o: %.c
	gcc $(C_FLAGS) -o $@ -c $<
clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -f $(OBJECTS_PUSH_SWAP) $(OBJECTS_CHECKER) $(OBJECTS_UTILS)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME_CHECKER) $(NAME_PUSH_SWAP)
	/bin/rm -f libft.a
re: fclean all
