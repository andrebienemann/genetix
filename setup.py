import distutils.core
import os


def get_sources(module):
    sources = list()
    for root, dirs, files in os.walk(f"genetix/{module}"):
        for file in files:
            if file.endswith(".c"):
                sources.append(os.path.join(root, file))
    return sources


def get_long_description():
    return open("README.md", "r").read()


distutils.core.setup(
    name="genetix",
    version="0.1.0rc1",
    description="A library for processing genetic information",
    long_description=get_long_description(),
    license="MIT",
    author="André Bienemann",
    author_email="andre.bienemann@gmail.com",
    url="https://github.com/andrebienemann/genetix",
    packages=[
        "genetix",
        "genetix/data",
        "genetix/parse",
    ],
    ext_package="genetix",
    ext_modules=[
        distutils.core.Extension(
            "seq",
            sources=get_sources("seq"),
        ),
        distutils.core.Extension(
            "stat",
            sources=get_sources("stat"),
        ),
    ],
)
