tomato = 0
watermolon = 1
tomato = bool(input("you see tomato:"))
if tomato == False:
	print("watermolon = " ,str(watermolon))
elif tomato == True:
	watermolon += 1
	print("watermolon = " ,str(watermolon))
