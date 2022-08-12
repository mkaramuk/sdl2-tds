NAME = game
OBJ_DIR = obj
SRC_DIR = src
INCLUDE_DIR = include
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
CFLAGS = -I$(INCLUDE_DIR) -g #-Wall -Wextra -Werror
LFLAGS = -lSDL2 -lSDL2_image
CC = g++

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@ 

clean:
	rm -rf $(OBJ_DIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all 

run: $(NAME)
	./$(NAME)

.PHONY: run re fclean clean all