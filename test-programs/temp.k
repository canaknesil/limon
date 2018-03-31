
def println = @(a) {
	[print a + "\n"]
}

def arr = {# 1 2 3}
def str = "can"
[println [#[#arr 1 9] 1]]
[println [#[#str 1 'k'] 1]]

[println arr]
[println str]

