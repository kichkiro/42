#!/bin/bash

set -e

# CLEAN DOCKER-USER CHAIN ----------------------------------------------------->
iptables -F DOCKER-USER

# SET RETURN ------------------------------------------------------------------>
iptables -A DOCKER-USER -s 0.0.0.0/0 -d 0.0.0.0/0 -j RETURN

# DROP ALL EAST-WEST TRAFFIC -------------------------------------------------->
iptables -I DOCKER-USER -s 10.0.0.0/24 -d 10.0.0.0/24 -j DROP
iptables -I DOCKER-USER -s 10.0.1.0/24 -d 10.0.1.0/24 -j DROP
iptables -I DOCKER-USER -s 10.0.2.0/24 -d 10.0.2.0/24 -j DROP
iptables -I DOCKER-USER -s 10.0.3.0/24 -d 10.0.3.0/24 -j DROP
iptables -I DOCKER-USER -s 10.0.4.0/24 -d 10.0.4.0/24 -j DROP

# APP SEGMENT ----------------------------------------------------------------->
iptables -I DOCKER-USER -s 10.0.1.1 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.1.2 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.1.1 -d 10.0.1.2 -p tcp --dport 5432 -j ACCEPT

# LOG-SYSTEM SEGMENT ---------------------------------------------------------->
iptables -I DOCKER-USER -s 10.0.2.1 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.2.2 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.2.3 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.2.3 -d 10.0.2.1 -p tcp --dport 9200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.2.2 -d 10.0.2.1 -p tcp --dport 9200 -j ACCEPT
iptables -I DOCKER-USER -p udp --dport 5000 -j ACCEPT
iptables -I DOCKER-USER -p udp --sport 5000 -j ACCEPT

# MONITOR-SYSTEM SEGMENT ------------------------------------------------------>
iptables -I DOCKER-USER -s 10.0.3.1 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.2 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.3 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.4 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.2 -d 10.0.3.1 -p tcp --dport 9090 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.1 -d 10.0.3.3 -p tcp --dport 9093 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.1 -d 10.0.1.1 -p tcp --dport 8000 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.4 -d 10.0.1.2 -p tcp --dport 5432 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.1 -d 10.0.3.4 -p tcp --dport 9187 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.3 -d 10.0.4.1 -p tcp --dport 8443 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.3.1 -d 10.0.3.3 -p tcp --dport 9113 -j ACCEPT

# PROXY-WAF SEGMENT ----------------------------------------------------------->
iptables -I DOCKER-USER -s 10.0.4.1 -d 10.0.0.1 -p tcp --dport 8200 -j ACCEPT
iptables -I DOCKER-USER -s 10.0.4.1 -d 10.0.1.1 -p tcp --dport 8000 -j ACCEPT

# SET IPTABLES IN STATEFUL MODE ----------------------------------------------->
iptables -I DOCKER-USER -m state --state ESTABLISHED,RELATED -j ACCEPT
