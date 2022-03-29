# SHELL
SHELL := /bin/bash

# DIRECTORIES
ROOT := $(shell pwd)

# ENVIRONMENT VARIABLES
PYTHONPATH := "PYTHONPATH=$(ROOT)"
CFLAGS_COVERAGE := CFLAGS="-coverage"
CFLAGS_OPTIMISATION := CFLAGS="-O3"

# STRINGS
DIVIDER_STRING := "---------------------------------------------------------"
PY_COVERAGE_STRING := "              Python Code Coverage Report             "

# TEMPLATES
COMMAND_TEMPLATE := "  \033[36m%s\033[0m %s\n"

# HELP
.PHONY: help
help all:
	@echo "Available Commands:"; \
	printf $(COMMAND_TEMPLATE) "setup" "Setup the project" ; \
	printf $(COMMAND_TEMPLATE) "format" "Format the source code"; \
	printf $(COMMAND_TEMPLATE) "unit-tests" "Execute unit tests"; \
	printf $(COMMAND_TEMPLATE) "py-coverage" "Display coverage for Python code"; \
	printf $(COMMAND_TEMPLATE) "c-coverage" "Display coverage for C code"; \
	printf $(COMMAND_TEMPLATE) "memory-tests" "Execute memory tests"; \
	printf $(COMMAND_TEMPLATE) "build-lib" "Build the library"; \
	printf $(COMMAND_TEMPLATE) "publish-lib" "Publish the library on PyPI"; \
	printf $(COMMAND_TEMPLATE) "serve-docs" "Server the documentation locally"; \
	printf $(COMMAND_TEMPLATE) "build-docs" "Build the documentation website"; \
	printf $(COMMAND_TEMPLATE) "deploy-docs" "Deploy the documentation"; \
	

# SETUP
.PHONY: setup
setup:
	@virtualenv -p python3 $(ROOT)/venv; \
	source $(ROOT)/venv/bin/activate; \
	pip install -r requirements.txt; \

# FORMAT
.PHONY: format
format:
	@source $(ROOT)/venv/bin/activate; \
	black $(ROOT)/genetix $(ROOT)/tests $(ROOT)/setup.py; \
	isort --profile black $(ROOT)/genetix $(ROOT)/tests; \

# UNIT TESTS
.PHONY: unit-tests
unit-tests:
	@source $(ROOT)/venv/bin/activate; \
	export $(CFLAGS_COVERAGE); \
	python $(ROOT)/setup.py build_ext --inplace; \
	python -B -m coverage run --source $(ROOT)/genetix -m unittest discover $(ROOT)/tests/unit; \
	rm $(ROOT)/genetix/*.so; \

# PYTHON COVERAGE
.PHONY: py-coverage
py-coverage:
	@source $(ROOT)/venv/bin/activate; \
	echo $(DIVIDER_STRING); \
	echo $(PY_COVERAGE_STRING); \
	echo $(DIVIDER_STRING); \
	coverage report -m; \
	echo $(DIVIDER_STRING); \

# C COVERAGE
.PHONY: c-coverage
c-coverage:
	@source $(ROOT)/venv/bin/activate; \
	gcovr; \

# MEMORY TESTS
.PHONY: memory-tests
memory-tests:
	@source $(ROOT)/venv/bin/activate; \
	python $(ROOT)/setup.py build_ext --inplace; \
	cd $(ROOT)/tests/memory; \
	export $(PYTHONPATH); \
	ls *.py | xargs -n 1 -P 2 python -B; \
	rm $(ROOT)/genetix/*.so; \

# BUILD LIBRARY
.PHONY: build-lib
build-lib:
	@ \
	source $(ROOT)/venv/bin/activate; \
	export $(CFLAGS_OPTIMISATION); \
	python $(ROOT)/setup.py build; \

# PUBLISH LIBRARY
.PHONY: publish-lib
publish-lib:
	@source $(ROOT)/venv/bin/activate; \
	python $(ROOT)/setup.py sdist bdist_wheel; \
	twine upload $(ROOT)/dist/*; \

# SERVE DOCUMENTATION
.PHONY: serve-docs
serve-docs:
	@source $(ROOT)/venv/bin/activate; \
	mkdocs serve; \

# BUILD DOCUMENTATION
.PHONY: build-docs
build-docs:
	@source $(ROOT)/venv/bin/activate; \
	mkdocs build; \

# DEPLOY DOCUMENTATION
.PHONY: deploy-docs
deploy-docs:
	@source $(ROOT)/venv/bin/activate; \
	mkdocs gh-deploy --force; \