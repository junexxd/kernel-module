obj-m += command-line.o
obj-m += exit.o
obj-m += claexit.o

claexit-objs := command-line.o exit.o
PWD := $(CURDIR)
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
