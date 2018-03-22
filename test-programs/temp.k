
def count = 0
def f = @() { 
	count += 1
}

[print [f]] [print [f]]
