# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pjulca <pjulca@student.42barcelon>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 00:31:15 by pjulca            #+#    #+#              #
#    Updated: 2023/12/02 19:39:43 by pjulca           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------COLORS-----------------------------------#

DEF_COLOR		=	\033[0;39m
DEL_LINE		=	\033[2K
NO_COLOR		=	\033[0m
BOLD_PURPLE		=	\033[1;35m
BOLD_CYAN		=	\033[1;36m
BOLD_YELLOW		=	\033[1;33m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
WHITE			=	\033[0;97m

#-----------------------------------VARIABLES----------------------------------#

NAME 		= libft.a

# DIRS

SRC_DIR 	= src/

OBJ_DIR 	= obj/

INCLUDE_DIR = inc/

#------------------------------------SOURCES-----------------------------------#

IS_DIR 		= is/
IS_FILES	= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint

LST_DIR 	= lst/
LST_FILES 	= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back \
			ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

MEM_DIR 	= mem/
MEM_FILES 	= ft_bzero ft_calloc ft_memcmp ft_memcpy ft_memchr ft_memmove \
			ft_memset

PUT_DIR 	= put/
PUT_FILES 	= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd 

STR_DIR 	= str/
STR_FILES 	= ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat \
			ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr \
			ft_strtrim ft_substr ft_global_split

TO_DIR 		= to/
TO_FILES 	= ft_atoi ft_itoa ft_tolower ft_toupper

GNL_DIR		= gnl/
GNL_FILES 	= gnl_bonus gnl_utils_bonus

SRC_FILES	+=	$(addprefix $(IS_DIR),$(IS_FILES))
SRC_FILES	+=	$(addprefix $(LST_DIR),$(LST_FILES))
SRC_FILES	+=	$(addprefix $(MEM_DIR),$(MEM_FILES))
SRC_FILES	+=	$(addprefix $(PUT_DIR),$(PUT_FILES))
SRC_FILES	+=	$(addprefix $(STR_DIR),$(STR_FILES))
SRC_FILES	+=	$(addprefix $(TO_DIR),$(TO_FILES))
SRC_FILES	+=	$(addprefix $(GNL_DIR),$(GNL_FILES))

SRCS 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

#-----------------------------------COMPILATE----------------------------------#

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar -rcs

RM = rm -f

RMDIR = rm -rf

MK = mkdir -p

HEADER = libft.h

INCLUDE = -I

#-------------------------------------RULES------------------------------------#

all: DIR $(NAME)

$(NAME) :: $(OBJS) 
		@$(AR) $(NAME) $(OBJS)
		@echo "$(GREEN)\n ✓✓✓ Created $(NAME)\n$(DEF_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(INCLUDE_DIR)libft.h Makefile
		@printf "${DEL_LINE}\r${YELLOW}Compiling!➟➟➟ ${BLUE}$@${NC}"
		@$(CC) $(CFLAGS) $(INCLUDE)$(INCLUDE_DIR) -c $< -o $@

DIR:
			@-mkdir -p $(OBJ_DIR)
			@-mkdir -p $(OBJ_DIR)$(IS_DIR)
			@-mkdir -p $(OBJ_DIR)$(LST_DIR)
			@-mkdir -p $(OBJ_DIR)$(MEM_DIR)
			@-mkdir -p $(OBJ_DIR)$(PUT_DIR)
			@-mkdir -p $(OBJ_DIR)$(STR_DIR)
			@-mkdir -p $(OBJ_DIR)$(TO_DIR)
			@-mkdir -p $(OBJ_DIR)$(GNL_DIR)
$(NAME)	::
	@echo "$(YELLOW)Nothing to be done for $(NAME)$(DEF_COLOR)"
#---------------------------------clean_up-------------------------------------#

clean:
	@if [ -d ${OBJ_DIR} ]; then \
		${RMDIR} ${OBJ_DIR} ; \
		echo "${WHITE}${NAME}: ${RED}|-✗ Object Files Cleaned! ✗-|\n$(DEF_COLOR)" ; \
	else \
		echo "${YELLOW}${NAME}${GREEN} ☈ ${BLUE}|-✗ Object Files Already ${RED}Cleaned${BLUE}! ✗-|\n$(DEF_COLOR)" ; \
	fi

fclean:	clean
	@if [ -e ${NAME} ] ; then \
		${RM} ${NAME} ; \
		echo "${RED}|-✗ ${NAME} Fcleaned! ✗-|\n$(DEF_COLOR)" ;	\
	else \
		echo "${YELLOW}${NAME}${GREEN} ☈ ${BLUE}|-✗ Name File Already ${RED}Fcleaned${BLUE}! ✗-|\n$(DEF_COLOR)" ; \
	fi

re: fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for $(NAME)!~$(DEF_COLOR)";

git: fclean
	@echo "Pulled recursive"
	@echo "Commit:"
	@read MSG; \
	git commit -am "$$MSG"
	git push

show:
	@printf "NAME		: ${NAME}\n"
	@printf "UNAME		: ${UNAME}\n"
	@printf "CC			: ${CC}\n"
	@printf "CFLAGS		: ${CFLAGS}\n"
	@printf "IFLAGS		: ${HEADERS}\n"
	@printf "SRC		: ${SRCS}\n"
	@printf "OBJS		: ${OBJS}\n"

norm:
	@printf "${WHITE}|⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻⎻|\n${RESET}"
	@printf "${WHITE}| PUSH_SWAP |\n${RESET}"
	@printf "${WHITE}| BY PJULCA |\n${RESET}"
	@printf "${WHITE}|___________|\n${RESET}"
	@norminette $(SRCS) $(HEADER_CORE) | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "\033[0;91m"$$1" "$$2; \
	else print "${RESET}"$$0}'

.PHONY: fclean, all, clean, re, norm
