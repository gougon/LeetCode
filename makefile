CC = g++
path = 79-WordSearch
name = wordSearch
utils = utils/Utils
exe = $(path)/$(name)
obj = $(utils).o $(path)/$(name).o

all:$(obj)
	$(CC) -o $(exe) $(obj)
.PHONY:clean
clean:
	rm -rf $(obj) $(exe)