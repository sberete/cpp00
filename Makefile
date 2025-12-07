CC = g++
CFLAGS = -Werror -Wextra -Wall -MMD -g3 -fPIC
INCLUDES = -Iincludes
SRC_DIR = src
OBJ_DIR = objs

SRCS = $(shell find $(SRC_DIR) -name '*.cpp')
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

DEPENDS = $(OBJS:.o=.d)

NAME = cpp
-include $(DEPEND)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY:
re: fclean all