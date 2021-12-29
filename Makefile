CC 		= cc
CCFLAGS = -Wall -Werror -Wextra -g
INCLUDE	= -I./includes

COMMON_OBJ = utils.o stack.o str_utils.o swap.o swipeup.o swipedown.o

OBJ		= main.o instra.o
EXEC	= pushswap
B_DIR	= build
B_OBJ	= $(addprefix $(B_DIR)/, $(OBJ))
C_OBJ	= $(addprefix $(B_DIR)/, $(COMMON_OBJ))

all: $(EXEC)

$(EXEC): $(C_OBJ) $(B_OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

common: $(C_OBJ)

clean:
	rm -f $(B_OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(EXEC)

.PHONY: all clean fclean debug
