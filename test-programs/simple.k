


def printArr = @(arr, size) {
    def i = 0
    (while i < size ? (
        [print [# arr i]] + "\n"]
        i += 1
    ))
}

def size = 5
def arr = [# size]

def i = 0
(while i < size ? (
    [# arr i i] +=
    i += 1
))

printArr(arr, size);

0