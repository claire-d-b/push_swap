.SUFFIXES:

NAME	= push_swap

CC			= clang
HEADER		= -include includes/push_swap.h
HEADER_FILE	= includes/push_swap.h
CFLAGS		= -Wall -Wextra -Werror
DFLAGS		= -MM

SRCS_PATH = srcs/
INCLUDE_PATH	= includes/
OBJ_PATH		=	obj/
DEPS_PATH		=	deps/

C_SUFFIX		= .c
O_SUFFIX		= .o
D_SUFFIX		= .d

LIST =		combine \
			errors \
			find_sort_style \
			free \
			ft_split \
			init \
			list \
			max_min \
			mem \
			nb_utils \
			print \
			push_swap \
			push \
			rotate \
			small_lists \
			sort_utils \
			sort \
			stack_utils \
			swap \
			utils \

LIST_C 		=	$(addsuffix $(C_SUFFIX), $(LIST))
LIST_O 		=	$(addsuffix $(O_SUFFIX), $(LIST))
LIST_D 		=	$(addsuffix $(D_SUFFIX), $(LIST))

SRCS		=	$(addprefix $(SRCS_PATH), $(LIST_C))
OBJS		=	$(addprefix $(OBJ_PATH), $(LIST_O))
DEPS		=	$(addprefix $(DEPS_PATH), $(LIST_D))

RM			= rm -f
RM_DIR		= rm -rf

$(OBJ_PATH)%.o:		$(SRCS_PATH)%.c $(HEADER_FILE)
			@mkdir -p obj/
			$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(DEPS_PATH)%.d:	$(SRCS_PATH)%.c
			@mkdir -p deps/
			$(CC) $(CFLAGS) $(HEADER) -o $@ $(DFLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS) $(DEPS)
				$(CC) $(OBJS) -o $@

clean:			
				$(RM_DIR) $(OBJ_PATH) $(DEPS_PATH)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

