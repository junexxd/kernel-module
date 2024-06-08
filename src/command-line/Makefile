obj-m += cla.o
obj-m += exit.o
obj-m += claexit.o

claexit-objs := cla.o exit.o
PWD := $(CURDIR)
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
