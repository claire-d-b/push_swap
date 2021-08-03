SRCS =	./combine.c\
	./find_sort_style.c\
	./init.c\
	./list.c\
	./max_min.c\
	./print.c\
	./push_swap.c\
	./push.c\
	./rotate.c\
	./sort_utils.c\
	./sort.c\
	./stack_utils.c\
	./swap.c\
	./utils.c\

RENAME		= mv a.out push_swap
OBJ			= $(SRCS:.c=.o)
NAME		= push_swap
FS			= a.out.dSYM push_swap.dSYM 
CC			= clang
RM			= rm -f
RM_DIR		= rm -rf
CFLAGS		= -Wall -Wextra -Werror
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

