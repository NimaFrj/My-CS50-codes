# TODO
import cs50
j = cs50.get_int("enter : ")
while j < 1 or j > 8:
    j = cs50.get_int("enter : ")
j += 1
for i in range(1, j):
    print(" " * (j-i-1), "#"*i, "  ", "#" * i, sep="")
