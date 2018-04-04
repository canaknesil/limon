
def cont = true
(while cont ? {
    def s = [scan]
    (s == "" ? cont = false : 
        [print s + "\n"])
})