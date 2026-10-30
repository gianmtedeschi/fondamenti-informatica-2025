# Fondamenti di Informatica 2025

Material for the exercise sessions of *Fondamenti di Informatica* (Computer Science Fundamentals): handouts with exercises and their C solutions.

## Structure

One folder per exercise session:

| Session | Topic |
|---------|-------|
| 01 | Binary encoding and Boolean logic |
| 02 | Input/output and `if` |
| 03 | Loops and `switch` |
| 04 | Arrays |
| 05 | Strings and matrices |
| 06 | `typedef` and `struct` |
| 07 | Functions |
| 08 | Linked lists |
| 09 | Files and `argc`/`argv` |

Inside each session folder:

```
[FI-2025] NN-topic/
├── preamble.tex      # shared LaTeX preamble
└── NN-topic/
    ├── NN-topic.tex  # handout source
    ├── NN-topic.pdf  # compiled handout
    ├── ex/           # one .tex file per exercise
    └── src/          # C solutions
```

To rebuild a handout, run `latexmk -pdf NN-topic.tex` from its folder.
