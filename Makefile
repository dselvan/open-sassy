all:
	$(MAKE) -C src/
	$(MAKE) -C test/ test  
clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C test/ clean