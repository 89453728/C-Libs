GG = g++
CFLAGS = -Wall -g
MAIN = ../test/main
OFILES = narray.o strfunc.o cmp.o
EXEC = ../test/exec
INCLUDES = -I./../src/

all: done

done: move
	@echo "Done!"

move: $(OFILES)
	@echo "Moving all .o to test"
	@cp $? ../test/

%.o: %.cc %.h
	@echo "Making .o files"
	$(GG) $(CFLAGS) -c $<

compile:
	@echo "Linking .o files and  making executable"
	@$(GG) $(CFLAGS) -c $(INCLUDES) $(MAIN).cc -o $(MAIN).o
	@$(GG) $(CFLAGS) -o $(EXEC) ../test/$(OFILES) $(MAIN).o
clean:
	@rm -r *.o
	@rm -r ../test/*.o
	@rm ../test/exec
