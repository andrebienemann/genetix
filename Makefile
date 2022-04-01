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
	grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
	awk 'BEGIN {FS = ":.*?## "}; {printf $(COMMAND_TEMPLATE), $$1, $$2}'; \

# SETUP
.PHONY: setup
setup: ## Setup the project
	@virtualenv -p python3 $(ROOT)/venv; \
	source $(ROOT)/venv/bin/activate; \
	pip install -r requirements.txt; \

# FORMAT
.PHONY: format
format: ## Format the source code
	@source $(ROOT)/venv/bin/activate; \
	black $(ROOT)/genetix $(ROOT)/tests $(ROOT)/setup.py; \
	isort --profile black $(ROOT)/genetix $(ROOT)/tests; \

# UNIT TESTS
.PHONY: unit-tests
unit-tests: ## Execute unit tests
	@source $(ROOT)/venv/bin/activate; \
	export $(CFLAGS_COVERAGE); \
	python $(ROOT)/setup.py build_ext --inplace; \
	python -B -m coverage run --source $(ROOT)/genetix -m unittest discover $(ROOT)/tests/unit; \
	rm $(ROOT)/genetix/*.so; \

# PYTHON COVERAGE
.PHONY: py-coverage
py-coverage: ## Display coverage for Python code
	@source $(ROOT)/venv/bin/activate; \
	echo $(DIVIDER_STRING); \
	echo $(PY_COVERAGE_STRING); \
	echo $(DIVIDER_STRING); \
	coverage report -m; \
	echo $(DIVIDER_STRING); \

# C COVERAGE
.PHONY: c-coverage
c-coverage: ## Display coverage for C code
	@source $(ROOT)/venv/bin/activate; \
	gcovr; \

# MEMORY TESTS
.PHONY: memory-tests
memory-tests: ## Execute memory tests
	@source $(ROOT)/venv/bin/activate; \
	python $(ROOT)/setup.py build_ext --inplace; \
	cd $(ROOT)/tests/memory; \
	export $(PYTHONPATH); \
	ls *.py | xargs -n 1 -P 2 python -B; \
	rm $(ROOT)/genetix/*.so; \

# BUILD LIBRARY
.PHONY: build-lib
build-lib: ## Build the library
	@source $(ROOT)/venv/bin/activate; \
	export $(CFLAGS_OPTIMISATION); \
	python $(ROOT)/setup.py build; \

# PUBLISH LIBRARY
.PHONY: publish-lib
publish-lib: ## Publish the library on PyPI
	@source $(ROOT)/venv/bin/activate; \
	python $(ROOT)/setup.py sdist bdist_wheel; \
	twine upload $(ROOT)/dist/*; \

# SERVE DOCUMENTATION
.PHONY: serve-docs
serve-docs: ## Server the documentation locally
	@source $(ROOT)/venv/bin/activate; \
	mkdocs serve; \

# BUILD DOCUMENTATION
.PHONY: build-docs
build-docs: ## Build the documentation website
	@source $(ROOT)/venv/bin/activate; \
	mkdocs build; \

# DEPLOY DOCUMENTATION
.PHONY: deploy-docs
deploy-docs: ## Deploy the documentation
	@source $(ROOT)/venv/bin/activate; \
	mkdocs gh-deploy --force; \
