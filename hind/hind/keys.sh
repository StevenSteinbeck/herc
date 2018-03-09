#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    keys.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stestein <stestein@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 14:32:07 by stestein          #+#    #+#              #
#    Updated: 2018/03/06 14:32:08 by stestein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cp ~/.zshrc ~/.zshrc_backup

echo "export FINDER42_UID=d249ad9b6ac4a146f919aae1b04cf1d7b66a9c2a76a644e793aa0a269a5fa8b3" \
>> ~/.zshrc
echo "export FINDER42_SECRET=4668d258b645f0ec47185080ec16fd3e789878133ced2b0812fe0d5dda3264f7" \
>> ~/.zshrc

zsh
