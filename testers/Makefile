all: test02 test01 test03

clean:
	@rm -rf Philosphers-42Project-Tester
	@rm -rf LazyPhilosophersTester
	@rm -rf socrates

# -------- 01 --------

test01: Philosphers-42Project-Tester
	zsh Philosphers-42Project-Tester/start.sh ../ 1 # TODO use 0 to tests both

Philosphers-42Project-Tester:
	@echo "Cloning $@"
	@git clone git@github.com:newlinuxbot/Philosphers-42Project-Tester.git

# -------- 02 --------

test02: LazyPhilosophersTester/Makefile
	@make -C LazyPhilosophersTester test

LazyPhilosophersTester/Makefile: LazyPhilosophersTester
	@echo "test:\n	bash test.sh ../../philo/philo" > $@

LazyPhilosophersTester:
	@echo "Cloning $@"
	@git clone git@github.com:MichelleJiam/LazyPhilosophersTester.git

# -------- 03 --------

test03: socrates/Makefile
	@make -C socrates test

socrates/Makefile: socrates
	@echo "test:\n	python3 socrates.py ../.." > $@

socrates:
	@echo "Cloning $@"
	@git clone git@github.com:nesvoboda/socrates.git
