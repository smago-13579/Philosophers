# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smago <smago@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 15:12:50 by smago             #+#    #+#              #
#    Updated: 2021/01/28 17:10:25 by smago            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

HEADER_DIR = headers/

HEADER = philo_one.h

SRCS = main.c ft_parse.c ft_error.c ft_init.c ft_clear.c ft_timez.c \
		ft_lock_unlock.c

OBJDIR = ./obj/

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)

FLAGS = -Wall -Wextra -Werror -I $(HEADER_DIR)

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) $(HEADER_DIR)$(HEADER)
	gcc $(FLAGS) $(OBJS) -o $@

$(OBJDIR)%.o : %.c 
	gcc -c $(FLAGS) $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

