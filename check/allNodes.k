
def println = @(a) {
	[print a + "\n"]
}

def printNode = @(a) {
	[print "\n--- " + a + " ---\n\n"]
}


[printNode "AProgram"]
[printNode "OneExpEL"]
[printNode "MulExpEL"]


[printNode "ScopeExp"]
{
	[println {1} + "\t(1)"]
	def a = 1
	def b = 3
	{
		def a = 2
		b = 4
		def c = 5
		[println a + "\t(2)"]
		[println b + "\t(4)"]
		[println c + "\t(5)"]
	}
}



[printNode "DefExp"]
{
	[println def a + "\t(#<null>)"]
	[println a + "\t(#<null>)"]
}



[printNode "AssignExp"]
{
	def a = 1
	[println (a = 2) + "\t(2)"]
	[println a + "\t(2)"]
}


[printNode "IfExp"]
{
	def a = true
	def b = false
	[println (a ? 1) + "\t(1)"]
	[println (b ? 1) + "\t(#<null>)"]
	(a ? [print 1]) [println "\t(1)"]
	(b ? [print 1]) [println "\t()"]
}


[printNode "IfElseExp"]
{
	def a = true
	def b = false
	[println (a ? 1 : 2) + "\t(1)"]
	[println (b ? 1 : 2) + "\t(2)"]
	(a ? [print 1] : [print 2]) [println "\t(1)"]
	(b ? [print 1] : [print 2]) [println "\t(2)"]
}


[printNode "WhileExp"]
{
	def a = 0
	[println (while a < 0 ? a += 1) + "\t(#<null>)"]
	a = 0
	[println (while a < 3 ? a += 1) + "\t(3)"]
	a = 0
	(while a < 3 ? (
		[print a + " "]
		a += 1
	))
	[println "\t(0 1 2)"]
}


[printNode "PrintExp"]
{
	[print null] [println "\t(#<null>)"]
	[print 1] [println "\t(1)"]
	[print true] [println "\t(#<true>)"]
	[print "Can"] [println "\t(Can)"]
	[print 'C'] [println "\t(C)"]
	[print {#1 2}] [println "\t({1 2})"]
	[print @() {1}] [println "\t(#<procedure>)"]
}


[printNode "VarExp"]
{
	def a = 1
	[println a + "\t(1)"]
}