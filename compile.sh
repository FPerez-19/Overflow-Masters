#!/bin/bash
# Build guide.pdf from guide.tex
set -e

if command -v latexmk >/dev/null 2>&1; then
    latexmk -pdf -interaction=nonstopmode guide.tex
else
    # Fallback: latexmk not installed, run pdflatex twice by hand
    # (the 2nd pass resolves the table of contents and the "Page X of Y" refs)
    pdflatex -interaction=nonstopmode guide.tex
    pdflatex -interaction=nonstopmode guide.tex
fi
