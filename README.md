# Hind
A tool used to track and map the position of users that are logged into the 42 domain network

YOU MUST INSTALL RUBY AND OATH2

xcode: xcode-select --install

homebrew: ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

ruby: brew install ruby

oauth: gem install oauth2

oauth: gem install google-api-client


This program uses Ruby to contact 42's API and C to
generate a map from the corresponding data.

Execution:

1: The .rb file contacts the API with the provided logins.txt filter,
   gathers and sorts data, and outputs the selected data in a file called
   log.txt. This file must exist before running the command.

	to get proper API access: 
	sh keys.sh  (obviously the keys included in this file are invalid, but get your own from the API and ther them here)
	ruby 42api.rb logins.txt

2: The map generator .c file, once compiled, will examine the log.txt and generate a map
   from that data. If only interested in testing the map generator, altering
   the information in log.txt will prove advantegous. Also, the program need not be
   re-compiled when changing log.txt. Everytime ./a.out is run, it searches for the 
   log.txt file and gathers its data
	
	gcc mapgen.c     after 1st compilation ===>  just ./a.out
	./a.out

General Information:

1: The mapping program reads data from a ruby script generated log.txt file.
   As such, the format of log.txt never changes when freshly run, and so
   the program was designed with certain dependencies. Namely, a space
   at the end of each line in log.txt. So for map testing purposes, make SURE
   you match the format of the original ruby generated log.txt file.

2: longlog.txt is a file I created to test the mapping power of the program. It has about    200,000 logins and locations, and runs just fine :)

	run: mv longlog.txt log.txt to have the mapping program use it as input.

# Hydra
A simple server and client
