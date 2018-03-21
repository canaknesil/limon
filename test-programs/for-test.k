


{
	def i=0;
	def __FOR_MODIFIER__ = @() {
		i++;
	}
	while (i < 10) {
		print(i + "\n");
		__FOR_MODIFIER__();
	}
}

// This is equal to

for (i = 0 : i < 10 : i++;) print(i + "\n");
