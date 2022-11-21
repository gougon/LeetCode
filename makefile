CC = g++
path = 658-FindKClosetElements
name = findKClosetElements
utils = utils/Utils
exe = $(path)/$(name)
obj = $(utils).o $(path)/$(name).o

all:$(obj)
	$(CC) -o $(exe) $(obj)
.PHONY:clean
clean:
	rm -rf $(obj) $(exe)