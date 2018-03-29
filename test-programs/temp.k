

def class = @(n) {
    def a = n
    @(msg) {
        @() {a}
    }
}

def obj = [class 5]
[print [[obj "getA"]]]

