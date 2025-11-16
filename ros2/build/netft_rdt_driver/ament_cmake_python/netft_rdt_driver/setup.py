from setuptools import find_packages
from setuptools import setup

setup(
    name='netft_rdt_driver',
    version='0.0.0',
    packages=find_packages(
        include=('netft_rdt_driver', 'netft_rdt_driver.*')),
)
