OUTPUTFILE=maze
INSTALLDIR=~/bin

.PHONY: all
all: $(OUTPUTFILE)

$(OUTPUTFILE): *.cpp *.hpp
	g++ -O3 -o ${OUTPUTFILE} *.cpp

.PHONY: install
install:
	mkdir -p $(INSTALLDIR)
	cp -p $(OUTPUTFILE) $(INSTALLDIR)

.PHONY: clean 
clean:
	rm -Rf $(OUTPUTFILE) ${INSTALLDIR}/$(OUTPUTFILE) *.gch
	