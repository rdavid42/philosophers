
SRC_PATH	=	src/

OBJ_PATH	=	obj/
INC_PATH	=	inc/

SRCS		=	$(shell ls $(SRC_PATH) | grep .c$$)
OBJS		=	$(patsubst %.c, $(OBJ_PATH)%.o,$(SRCS))

PLATFORM	:=	$(shell uname)
CC			=	gcc
HEADER		=	-I./$(INC_PATH) `sdl2-config --cflags`
FLAGS		=	-Ofast -g -Wall -Wextra -Werror -Wno-deprecated-declarations
VARS		=	-D_REENTRANT -D_THREAD_SAFE -DDEBUG

NAME		=	philo

ifeq "$(PLATFORM)" "WIN32"
NAME		+=	.exe
endif

SDL			=	`sdl2-config --libs`

ifeq "$(PLATFORM)" "Darwin" #MAC
GL			=	-lm -framework OpenGL -framework GLUT -framework Cocoa
else ifeq "$(PLATFORM)" "Linux" #LINUX
GL			=	-lGL -lGLU -lglut -lm
else ifeq "$(PLATFORM)" "Win32" #WINDOWS
GL			=	-lopengl32
endif

all: $(NAME)

$(NAME): $(OBJS)
ifeq "$(PLATFORM)" "Darwin"
	@$(CC) $(FLAGS) $(VARS) $(HEADER) $(SDL) $(GL) $(OBJS) -o $(NAME)
else ifeq "$(PLATFORM)" "Linux"
	@$(CC) $(FLAGS) $(VARS) $(HEADER) $(OBJS) -o $(NAME) $(SDL) $(GL)
endif

$(patsubst %, $(OBJ_PATH)%,%.o): $(SRC_PATH)$(notdir %.c)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $(FLAGS) $(VARS) $(HEADER) "$<" -o "$@"

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

l: re
	@./$(NAME)

launch: l

.PHONY: clean fclean re
