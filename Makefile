SHELL := /bin/bash

ROOT := $(shell pwd)

PYTHONPATH := "PYTHONPATH=$(ROOT)"
CFLAGS_COVERAGE := CFLAGS="-coverage"
CFLAGS_OPTIMISATION := CFLAGS="-O3"

COMMAND_TEMPLATE := "  \033[36m%s\033[0m %s\n"

.PHONY: help
help all:
	@echo "Available Commands:"; \
	grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(firstword $(MAKEFILE_LIST)) | \
	awk 'BEGIN {FS = ":.*?## "}; {printf $(COMMAND_TEMPLATE), $$1, $$2}'; \

.PHONY: setup
setup: ## Setup the project
	@virtualenv -p python3 $(ROOT)/venv; \
	source $(ROOT)/venv/bin/activate; \
	pip install -r requirements.txt; \

.PHONY: format
format: ## Format the source code
	@source $(ROOT)/venv/bin/activate; \
	black $(ROOT)/genetix $(ROOT)/tests $(ROOT)/setup.py; \
	isort --profile black $(ROOT)/genetix $(ROOT)/tests; \

.PHONY: unit-tests
unit-tests: ## Execute unit tests
	@source $(ROOT)/venv/bin/activate; \
	export $(CFLAGS_COVERAGE); \
	python $(ROOT)/setup.py build_ext --inplace; \
	python -B -m coverage run --source $(ROOT)/genetix -m unittest discover $(ROOT)/tests/unit; \
	rm $(ROOT)/genetix/*.so; \

.PHONY: py-coverage
py-coverage: ## Display coverage for Python code
	@source $(ROOT)/venv/bin/activate; \
	coverage report -m; \

.PHONY: c-coverage
c-coverage: ## Display coverage for C code
	@source $(ROOT)/venv/bin/activate; \
	gcovr; \

.PHONY: memory-tests
memory-tests: ## Execute memory tests
	@source $(ROOT)/venv/bin/activate; \
	python $(ROOT)/setup.py build_ext --inplace; \
	cd $(ROOT)/tests/memory; \
	export $(PYTHONPATH); \
	ls *.py | xargs -n 1 -P 2 python -B; \
	rm $(ROOT)/genetix/*.so; \

.PHONY: build-lib
build-lib: ## Build the library
	@source $(ROOT)/venv/bin/activate; \
	export $(CFLAGS_OPTIMISATION); \
	python $(ROOT)/setup.py build; \

.PHONY: publish-lib
publish-lib: ## Publish the library on PyPI
	@source $(ROOT)/venv/bin/activate; \
	python $(ROOT)/setup.py sdist bdist_wheel; \
	twine upload $(ROOT)/dist/*; \

.PHONY: serve-docs
serve-docs: ## Server the documentation locally
	@source $(ROOT)/venv/bin/activate; \
	mkdocs serve; \

.PHONY: build-docs
build-docs: ## Build the documentation website
	@source $(ROOT)/venv/bin/activate; \
	mkdocs build; \

.PHONY: deploy-docs
deploy-docs: ## Deploy the documentation
	@source $(ROOT)/venv/bin/activate; \
	mkdocs gh-deploy --force; \
