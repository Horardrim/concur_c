all:
	@make -C main
	@make -C test

clean:
	@rm -rf output
	@make -C main clean
	@rm -rf `find -name "*.gcov"` test/valgrind.log

cov:
	@make -C main cov
	@make -C test cov

test:
	@make -C test test

gencov:
	@make -C main gencov
	@make -C test gencov

rpm:
	@make -C main package
	@rpmbuild --define "_topdir `pwd`/rpmbuild" -ba rpmbuild/SPECS/concur_c.spec

.PHONY: clean cov test gencov rpm
