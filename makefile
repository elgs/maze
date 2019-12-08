OUTPUTFILE=maze
INSTALLDIR=~/bin

.PHONY: all
all: $(OUTPUTFILE)

$(OUTPUTFILE): *.cpp
	g++ -O3 -o ${OUTPUTFILE} *.cpp

.PHONY: install
install:
	mkdir -p $(INSTALLDIR)
	cp -p $(OUTPUTFILE) $(INSTALLDIR)

.PHONY: clean 
clean:
	rm -Rf $(OUTPUTFILE) ${INSTALLDIR}/$(OUTPUTFILE)