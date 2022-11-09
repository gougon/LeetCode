CC = g++
path = 739-DailyTemperatures
name = dailyTemperatures
utils = utils/Utils
exe = $(path)/$(name)
obj = $(utils).o $(path)/$(name).o

all:$(obj)
	$(CC) -o $(exe) $(obj)
.PHONY:clean
clean:
	rm -rf $(obj) $(exe)