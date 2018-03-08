
def f() {
    def n=0;
    @() { n=n+1; };
}

def g=f();
print(g());
print(g());

0;