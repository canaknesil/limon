
def create = @() {
	def prev = ""
	@(msg) {

		prev = msg
		if msg == "WALK" (
			[print "I am walking\n"]
		) : (

		)

		(
			prev = msg 
			msg == "WALK" ? 
			[print "I am walking\n"] 
			[asdf] :
			(msg == "RUN" ? [print "I am running\n"]
			: [noMethode msg]
		)
	}
}

def i = 0
(while i < 5 ? [print i])



(for i = 0, i < 5, i += 1, [print i])

a = b < 5 ? 1 : 2

a = if b < 5 ? 1 else 2