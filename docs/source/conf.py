# -- Project information -----------------------------------------------------

project = 'PathFinder'
author = 'Andrew Gibbs'
release = '1.1.1'

extensions = [
    "myst_parser",
    "sphinx.ext.mathjax",  # For math rendering
]

source_suffix = {
    '.rst': 'restructuredtext',
    '.md': 'markdown',
}

myst_enable_extensions = [
    "dollarmath",   # Enables $...$ and $$...$$
    "amsmath",      # Enables \[...\] and equation environments
]
