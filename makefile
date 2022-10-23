CC = g++
path = 973-KClosestPointsToOrigin
name = kClosestPointsToOrigin
utils = utils/Utils
exe = $(path)/$(name)
obj = $(utils).o $(path)/$(name).o

all:$(obj)
	$(CC) -o $(exe) $(obj)
.PHONY:clean
clean:
	rm -rf $(obj) $(exe)