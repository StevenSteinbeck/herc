#!/bin/bash

apt-get install openssh-server

cat /etc/ssh/sshd_config | sed 's/Port 22/Port 55555/' > .new_sshd_config

mv .new_sshd_config /etc/ssh/sshd_config

service sshd restart
