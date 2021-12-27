CC 		= cc
CCFLAGS = -Wall -Werror -Wextra
INCLUDE	= -I./includes

FILES 	= main utils stack instra str_utils
OBJ		= $(FILES:=.o)
EXEC	= pushswap
B_DIR	= build
B_OBJ	= $(addprefix $(B_DIR)/, $(OBJ))

all: $(EXEC)

$(EXEC): $(B_OBJ)
	$(CC) $(CCFLAGS) -o $(EXEC) $(B_OBJ)

$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

debug: CCFLAGS += -g
debug: all

clean:
	rm -f $(B_OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(EXEC)

.PHONY: all clean fclean all
