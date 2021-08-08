SRCS =	./srcs/combine.c\
	./srcs/errors.c\
	./srcs/find_sort_style.c\
	./srcs/free.c\
	./srcs/ft_split.c\
	./srcs/init.c\
	./srcs/list.c\
	./srcs/max_min.c\
	./srcs/mem.c\
	./srcs/nb_utils.c\
	./srcs/print.c\
	./srcs/push_swap.c\
	./srcs/push.c\
	./srcs/rotate.c\
	./srcs/small_lists.c\
	./srcs/sort_utils.c\
	./srcs/sort.c\
	./srcs/stack_utils.c\
	./srcs/swap.c\
	./srcs/utils.c\

RENAME		= mv a.out push_swap
OBJ			= $(SRCS:.c=.o)
NAME		= push_swap
FS			= a.out.dSYM push_swap.dSYM 
CC			= clang
RM			= rm -f
RM_DIR		= rm -rf
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
$(NAME):		$(OBJ)
#add CFLAGS
				@$(CC) $(CFLAGS) $(SRCS)
				@$(RENAME)
all:			$(NAME)
clean:
				@$(RM) $(OBJ)
fclean:			clean
				@$(RM) $(NAME)
				@$(RM_DIR) $(FS)
re:				fclean all	
.PHONY:			all clean fclean re

