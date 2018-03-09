#!/usr/bin/ruby

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    finder42.rb                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stestein <stestein@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/05 14:32:07 by stestein          #+#    #+#              #
#    Updated: 2018/03/06 14:32:08 by stestein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require "oauth2"
require "./includes/colors.rb"

$client = OAuth2::Client.new(
ENV['FINDER42_UID'],
ENV['FINDER42_SECRET'],
site: "https://api.intra.42.fr")
$token = $client.client_credentials.get_token

f = open('log.txt', File::TRUNC) {}

def find_user(login)
  begin
    f = File.open('log.txt', 'a')
    response = $token.get("/v2/users/#{login}/locations")
    while response.status != 200
      puts ("Check server connection").red
      sleep(5)
      if response.status == 200
        break
      end
    end
    if !response.parsed[0]["end_at"]
      puts (login.ljust(10) + ": " + response.parsed[0]["host"]).green.bold.blink
      f.write(login.ljust(10) + ": " + response.parsed[0]["host"])
      f.write(" \n")
      f.close
    else
      puts (login.ljust(10) + ": not logged in ¯\\_(ツ)_/¯").brown.bold
      puts ("(last login -> " + response.parsed[0]["host"] + ")").brown.bold
    end
  rescue
    puts (login.ljust(10) + ": not a valid username!").red.bold
  end
end

if ARGV[0]
  if File.file?(ARGV[0]) and File.extname(ARGV[0]) == ".txt"
    file = File.open(ARGV[0], "r").each_line do |line|
      line == "\n" ? next : login = line.strip
      find_user(login)
    end
    file.close
  else
    puts "Invalid file!"
  end
else
  puts "usage: " + $PROGRAM_NAME + " [file.txt]"
end
