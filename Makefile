##
## EPITECH PROJECT, 2023
## B-CPE-200-LYN-2-1-dante-leandre.cacarie
## File description:
## Makefile
##

TARGET_NAME	=	viewer
SOURCE_DIR	=	src
OBJECT_DIR	=	objects
HEADER_DIR	=	include

vpath %.c $(SOURCE_DIR)

SOURCES_FILES =	$(wildcard src/*.c)

OBJECTS	=	$(patsubst src/%.c, $(OBJECT_DIR)/%.o, $(SOURCES_FILES))

CC =	gcc

CFLAGS =	-I$(HEADER_DIR) \
			-W -Wall -Wextra \
			-Wno-unused-variable \
			-Wno-unused-parameter \
			-Wno-unused-but-set-variable \
			-Wno-unused-but-set-parameter \
			-Wno-deprecated-declarations \
			-g3

all:	directories $(TARGET_NAME)

directories: | $(SOURCE_DIR) $(OBJECT_DIR)

clean:
	@$(RM) -r ./$(OBJECT_DIR)/*.o

fclean: clean
	@$(RM) -r ./$(OBJECT_DIR)
	@$(RM) ./$(TARGET_NAME)
	@$(RM) vgcore*

re: fclean all
	@echo -e "\033[0;36m [Done] \033[0mredoing"

.PHONY: all clean fclean re

$(TARGET_NAME): $(OBJECTS)
	@$(CC) -o $(TARGET_NAME) $^
	@echo -e "🌑\e[35m -- BUILD SUCCESSFUL --\e[0m"

$(OBJECT_DIR):
	@mkdir -p $@

$(SOURCE_DIR):
	@echo "🌕\e[31m -- Error: source folder not found !\e[0m"

$(OBJECT_DIR)/%.o : %.c
	@$(CC) -c -o $@ $< $(CFLAGS)
	@echo -e "🌗\e[35m -- $@ successfully compiled --\e[0m"
