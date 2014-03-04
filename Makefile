# General Project-specific make file

CODE_DIR = $(wildcard */)

.PHONY: project_code
.PHONY: clean

project_code:
	-for d in $(CODE_DIR); do (cd $$d; $(MAKE)); done

clean:
	-for d in $(CODE_DIR); do (cd $$d; $(MAKE) clean); done
