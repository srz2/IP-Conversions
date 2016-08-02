
all:
	g++ ip-conversions.cpp -o ip-conversions
clean:
	rm ./ip-conversions
run:
	./ip-conversions
help:
	@echo 'IP Conversions is a simple utility to convert IP Addresses, network decimals, and host decimals to each other'
	@echo ''
	@echo 'To get started, build the app with "make" and then run the application "make run" to get to the menu seleciton'
	@echo 'Play with the different options and see what values are generated and reference the source code to understand'
	@echo 'the procedure to convert different values from one to another'
	@echo ''
	@echo 'The premise of this values and their conversions come into play with networking and working with network sockets'
	@echo 'and understanding the conversions will help to to understand how to best give functionality to your user'