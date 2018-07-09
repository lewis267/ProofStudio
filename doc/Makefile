.PHONY: element_regions_outline.pdf all clean

all: element_regions_outline.pdf

# Custom Buil Rules:

%.tex: %.raw
	./raw2tex $< > $@

%.tex: %.dat
	./dat2tex $< > $@

# Main Rules

element_regions_outline.pdf: element_regions_outline.tex
	latexmk -pdf -pdflatex="pdflatex -interaction=nonstopmode" -use-make element_regions_outline.tex

clean:
	latexmk -CA

