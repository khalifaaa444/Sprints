#Folders
OBJDIR = bin
SRCDIR = src
BUILDDIR = build


SHELL = /bin/bash
RM = rm -rf

CC = gcc
CFLAGS = -O1 -Wall -Werror -gdwarf-2
LDFLAGS = -lm
CPPFLAGS = $(foreach directory,$(INCDIRS),-I$(directory))

INCDIRS = $(sort $(dir $(HDRS)))

SRCS = $(shell find . -name '*.c' -type f)
HDRS = $(shell find . -name '*.h' -type f)
#OBJS = $(SRCS:.c=.o)
OBJS = $(patsubst %.c,$(OBJDIR)/%.o, $(SRCS))

#TARGET = $(lastword $(subst /, ,$(CURDIR)))
TARGET = $(BUILDDIR)/$(lastword $(subst /, ,$(CURDIR)))



.PHONY: all


all: $(TARGET) $(OBJDIR)

#$(OBJDIR) $(BUILDDIR):
#	mkdir -p $@

$(OBJDIR)/%.o: %.c
	@mkdir -p "$(dir $@)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ 
	

$(TARGET): $(OBJS)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	

.PHONY: run clean

run: $(TARGET)
	@$(SHELL) -c ./$(TARGET) 



clean:
	$(RM) $(OBJS)
	$(RM) $(TARGET)








######################################################################

#SHELL = /bin/bash
#RM = rm -rf

#CC = gcc
#CFLAGS = -Wall -Werror -gdwarf-2
#LDFLAGS = 
#CPPFLAGS = -I$(INC_DIR)

#SRC_DIR = src
#INC_DIR = include

#SRCS = $(wildcard $(SRC_DIR)/*.c)
#HDRS = $(wildcard $(INC_DIR)/*.h)
##OBJS= $(SRCS:.c=.o)
#OBJS = $(patsubst %.c,%.o,$(SRCS))

#TARGET = $(lastword $(subst /, ,$(CURDIR)))


#.PHONY: all


#all: $(TARGET)

#$(TARGET): $(OBJS)
#	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ 

#.PHONY: run clean

#run: $(TARGET)
#	@$(SHELL) -c ./$(TARGET) 



#clean:
#	$(RM) $(OBJS)
#	$(RM) $(TARGET)
















#################################################################

#SHELL = /bin/bash
#RM = rm -rf
#LDFLAGS = 
#CPPFLAGS =
#CC = gcc
#CFLAGS = -O1 -Wall -Werror -gdwarf-2

#SRCS = $(wildcard *.c)
#HDRS = $(wildcard *.h)
#OBJS = $(SRCS:.c=.o)

#TARGET = main

#.PHONY: all

#all: $(TARGET)

#$(TARGET): $(OBJS)
#	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

#.PHONY: run clean

#run: $(TARGET)
#	@$(SHELL) -c ./$(TARGET)

#clean:
#	$(RM) $(OBJS)
#	$(RM) $(TARGET) 




#########################################################################

#RM 	:= rm -rf
#CC 	:= gcc
#CFLAGS	:= -O1 -Wall -Werror

#DISASSEMPLE	:= objdump -d	

#TARGET	:= main
#SRCS	:= main.c foo.c bar.c
#OBJS	:= $(SRCS:.c=.o)
#ASMP	:= $(SRCS:.c=.s)

#all:$(TARGET) $(ASMP) $(TARGET).s

#%.o: %.c %.h
#	$(CC) $(CFLAGS) -c $<

#$(TARGET): $(OBJS)
#	$(CC) $^ -o $@ 

#%.s: %.o
#	$(DISASSEMPLE) $< > $@

#$(TARGET): $(OBJS)
#	$(CC) -lm $^ -o $@ 

#$(TARGET).s: $(TARGET) 
#	$(DISASSEMPLE) $< > $@


#.PHONY: clean
#clean:
#	$(RM) $(OBJS) $(TARGET) $(ASMP)




##########################################################################################

#RM		:= rm -rf
#COMPILE		:= $(CC) $(CFLAGS) -c
#LINK		:= $(CC)

#CC		:= gcc
#DISASSEMPLE	:= objdump -d	
#CFLAGS		:= -O1 -Wall -Werror

#TARGET	:= main
#SRCS	:= foo.c bar.c main.c
#ASMP	:= foo.s bar.s main.s
#OBJS	:= foo.o bar.o main.o

#all: $(TARGET) $(ASMP)

#$(TARGET): $(OBJS)
#	$(LINK) $^ -o $@ 

#foo.o:	 foo.c
#	$(COMPILE) $<

#bar.o:	 bar.c
#	$(COMPILE) $<

#main.o:	 main.c
#	$(COMPILE) $<

#foo.s:	foo.o
#	$(DISASSEMPLE) $< > $@

#bar.s:	bar.o
#	$(DISASSEMPLE) $< > $@

#main.s:	main.o
#	$(DISASSEMPLE) $< > $@

#$(TARGET).s: $(TARGET)
#	$(DISASSEMPLE) $< > $@


#.PHONY: clean
#clean:
#	$(RM) $(OBJS)
#	$(RM) $(TARGET)
#	$(RM) $(ASMP)










###############################################################################








#RM	:= rm -rf
#CC 	:= gcc
#CFLAGS 	:= -O1 -Wall -Werror
#SRC 	:= main.c foo.c bar.c
#OBJECT	:= main.o foo.o bar.o
#TARGET	:= main

#COMPILE	:= $(CC) $(CFLAGS) -c

#all: $(TARGET)

#$(OBJECT): $(SRC)
#	$(COMPILE) $(SRC)
#
#$(TARGET): $(OBJECT)
#	$(CC) -o $(TARGET) $(OBJECT)
#



#.PHONY: clean

#clean:
#	$(RM) $(TARGET) $(OBJECT) 
