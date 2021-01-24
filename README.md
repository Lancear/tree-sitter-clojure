![build status](https://github.com/dark-magic/tree-sitter-clojure/workflows/Build%20Parser/badge.svg)

# tree-sitter-clojure
#### Clojure grammar for tree-sitter

### Currently supported:
- literals (numerical, characters, strings, regexes)
- collections (lists, vectors, sets, maps)
- comments and optional ,
- identifiers (nil, true, false, symbols, and keywords)
- S-expressions
- macros (incl. (syntax) quoting and unquoting (splice) operators)
- anonymous functions
- destructuring (kinda)

### Todo:
- add testcases
- add more semanctic rules for the S-expressions (e.g. let, if, def, ...)
- solve destructuring better
- verify all special symbols, and literals are included
- if possible, limit radix digits to their base
