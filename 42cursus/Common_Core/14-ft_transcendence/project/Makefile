# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kichkiro <kichkiro@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 14:53:55 by kichkiro          #+#    #+#              #
#    Updated: 2024/07/04 20:37:08 by kichkiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

.PHONY: all up down start stop clean fclean re
.SILENT:

IMAGES?=

MAKEFLAGS += --no-print-directory

WHITE_BOLD=\033[1;37m
BLUE=\033[0;34m
NC=\033[0m

# Rules ----------------------------------------------------------------------->

all: up

up:
	@rm -rf .env
	@./setup/setup_iptables.sh
	@./setup/setup_vault.sh
	@echo "\n$(BLUE)[+] Compose $(WHITE_BOLD)LOG-SYSTEM $(BLUE)profile ..." 
	@docker compose -p "ft_transcendence" --profile log-system up -d
	@echo "\n$(BLUE)[+] Compose $(WHITE_BOLD)MONITOR-SYSTEM $(BLUE)profile ..." 
	@docker compose -p "ft_transcendence" --profile monitor-system up -d
	@echo "\n$(BLUE)[+] Compose $(WHITE_BOLD)APP $(BLUE)profile ..." 
	@docker compose -p "ft_transcendence" --profile app up -d 
	@echo "\n$(BLUE)[+] Compose $(WHITE_BOLD)PROXY-WAF $(BLUE)profile ..." 
	@docker compose -p "ft_transcendence" --profile proxy-waf up -d
	@rm -rf .env
	@echo

down:
	docker compose down

start:
	docker compose start

stop:
	docker compose stop

clean:
	@echo "\n$(BLUE)[+] Removing all containers$(NC)"
	@docker ps -qa | while read id; do \
		name=$$(docker inspect --format='{{.Name}}' $$id | sed 's/^\/\(.*\)/\1/'); \
		echo "    $(BLUE)Removing: $(WHITE_BOLD)$$name$(NC)"; \
		docker rm -f $$id > /dev/null 2>&1; \
	done
	@if [ -z "$(IMAGES)" ]; then \
		echo "\n$(BLUE)[+] Removing all images$(NC)"; \
		docker images -q | while read id; do \
			name=$$(docker inspect --format='{{.RepoTags}}' $$id); \
			echo "    $(BLUE)Removing: $(WHITE_BOLD)$$name$(NC)"; \
			docker rmi -f $$id > /dev/null 2>&1; \
		done; \
	else \
		echo "\n$(BLUE)[+] Removing specified images$(NC)";\
		for image in $(IMAGES); do \
			id=$$(docker images -q $$image 2>/dev/null); \
			if [ ! -z "$$id" ]; then \
				name=$$(docker inspect --format="{{.RepoTags}}" $$id); \
				echo "    $(BLUE)Removing: $(WHITE_BOLD)$$name$(NC)"; \
				docker rmi -f $$id > /dev/null 2>&1; \
			fi; \
		done; \
	fi
	@echo "\n$(BLUE)[+] Removing all volumes$(NC)"
	@docker volume ls -q | while read id; do \
		echo "    $(BLUE)Removing: $(WHITE_BOLD)$$id$(NC)"; \
		docker volume rm $$id > /dev/null 2>&1; \
	done
	@echo "\n$(BLUE)[+] Removing all networks$(NC)"
	@docker network ls -q | while read id; do \
		name=$$(docker network inspect --format='{{.Name}}' $$id); \
		if [ "$$name" != "bridge" ] && [ "$$name" != "host" ] && [ "$$name" != "none" ]; then \
			echo "    $(BLUE)Removing: $(WHITE_BOLD)$$name$(NC)"; \
			docker network rm $$id > /dev/null 2>&1; \
		fi \
	done

fclean: clean
	@echo "\n$(BLUE)[+] Removing all build cache$(NC)"
	@-docker builder prune --all --force > /dev/null 2>&1
	@echo "\n$(BLUE)[+] Cleaning Completed$(NC)"

re: clean up
