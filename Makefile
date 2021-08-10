.SUFFIXES:

NAME	= push_swap

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -MMD -I includes/

SRCS_PATH = srcs/
INCLUDE_PATH	= includes/
OBJ_PATH		=	obj/

C_SUFFIX		= .c
O_SUFFIX		= .o

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

SRCS		=	$(addprefix $(SRCS_PATH), $(LIST_C))
OBJS		=	$(addprefix $(OBJ_PATH), $(LIST_O))
DEPS		=	$(LIST_O:.o=.d)

RM			= rm -f
RM_DIR		= rm -rf

$(OBJ_PATH)%.o:		$(SRCS_PATH)%.c
			@mkdir -p obj/
			$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $@

clean:			
				$(RM_DIR) $(OBJ_PATH)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re

-include		$(DEPS)