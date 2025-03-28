# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 14:53:55 by kichkiro          #+#    #+#              #
#    Updated: 2024/06/27 15:11:27 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

.PHONY: all up down start stop re clean banner
.SILENT:

# Rules ----------------------------------------------------------------------->

all: banner up

up: banner
	docker compose -f ./srcs/docker-compose.yml up -d

down: banner
	docker compose -f ./srcs/docker-compose.yml down

start: banner
	docker compose -f ./srcs/docker-compose.yml start

stop: banner
	docker compose -f ./srcs/docker-compose.yml stop

clean: banner
	echo "Removing all containers..."
	-docker rm -f $$(docker ps -qa)
	echo "\nRemoving all images..."
	-docker rmi -f $$(docker images -qa)
	echo "\nRemoving all volumes..."
	-docker volume rm $$(docker volume ls -q)
	echo "\nRemoving network..."
	-docker network rm $$(docker network ls -q) 2>/dev/null

banner:
	${info }
	${info ██╗███╗   ██╗ ██████╗███████╗██████╗ ████████╗██╗ ██████╗ ███╗   ██╗}
	${info ██║████╗  ██║██╔════╝██╔════╝██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║}
	${info ██║██╔██╗ ██║██║     █████╗  ██████╔╝   ██║   ██║██║   ██║██╔██╗ ██║}
	${info ██║██║╚██╗██║██║     ██╔══╝  ██╔═══╝    ██║   ██║██║   ██║██║╚██╗██║}
	${info ██║██║ ╚████║╚██████╗███████╗██║        ██║   ██║╚██████╔╝██║ ╚████║}
	${info ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝╚═╝        ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝}
	${info }

# ------------------------------------------------------------------------------
