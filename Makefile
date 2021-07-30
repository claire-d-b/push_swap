SRCS =	./ft_op.c\
	./insertion.c\
	./ft_algo.c\

RENAME		= mv a.out push_swap
OBJ			= $(SRCS:.c=.o)
NAME		= push_swap
FS			= a.out.dSYM minishell.dSYM
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

