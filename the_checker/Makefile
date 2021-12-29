CC 		= cc
CCFLAGS = -Wall -Werror -Wextra -g
INCLUDE	= -I../includes

B_DIR	= ../build
COMMON_FILES = utils stack str_utils swap swipeup swipedown
COMMON_OBJ = $(addprefix $(B_DIR)/, $(COMMON_FILES:=.o))

FILES = checker exec
OBJ	  = $(FILES:=.o)

EXEC	= ../checker
B_OBJ	= $(addprefix $(B_DIR)/, $(OBJ))

all: $(EXEC)

$(EXEC): common $(B_OBJ)
	$(CC) $(CCFLAGS) -o $(EXEC) $(B_OBJ) $(COMMON_OBJ)
$(B_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(INCLUDE) -o $@ -c $<

common:
	@make -C .. common

debug: CCFLAGS += -g

clean:
	rm -f $(B_OBJ)
	rm -rf $(B_DIR)

fclean: clean
	rm -f $(EXEC)

.PHONY: all clean fclean
