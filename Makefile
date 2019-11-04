# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makfile                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 15:08:05 by ehakam            #+#    #+#              #
#    Updated: 2019/11/04 20:57:01 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME = PRINT_N
SRC = *.c
BUDIR = .backup
CC = gcc

all: $(NAME) backup

restore:
	@[ -d "$(BUDIR)" ] && cp $(BUDIR)/* .

backup:
	@[ ! -d "$(BUDIR)" ] && mkdir $(BUDIR) && cp -f *.c *.a *.h $(BUDIR) && cp -f Makefile $(BUDIR)

$(NAME): $(SRC)
	@echo "Building $(NAME)..."
	@$(CC) $(SRC) libft.a -o $(NAME)

clean:
	@echo "Cleaning up..."
	@rm -rf $(NAME)
