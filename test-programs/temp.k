
def println = @(a) {
	[print a]
	[print "\n"]
}

[println 2 != 2]
[println 2 != 1]

[println true != true]
[println true != false]

[println "Can Aknesil" != "Can Aknesil"]
[println "Can Aknesil" != "CanAknesil"]

[println 'z' != 'z']
[println 'z' != 'x']

[println {1 2 3} != {1 2 3}]
[println {1 2 3} != {1 2 4}]

def f = @() {1}
def g = @() {1}

[println f != f]
[println f != g]
