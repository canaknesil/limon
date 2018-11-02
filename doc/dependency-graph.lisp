
;; First load cl-dependency-printer.lisp from https://github.com/canaknesil/cl-dependency-printer.git.
(print-dependency-graph 
 ("main" "interp")
 ("interp" "parser" "run-h" "env" "value" "garb-c")
 ("parser" "node")
 ("node" "run-h" "env" "value" "garb-c")
 ("run-h" "env" "value" "garb-c")
 ("env" "garb-c")
 ("value" "garb-c")
 ("garb-c"))
