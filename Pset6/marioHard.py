import cs50

numberOfBlocks = -1
while numberOfBlocks < 0:
    numberOfBlocks = cs50.get_int("Digite o número de blocos: ")

for i in range(numberOfBlocks):
    for j in range(numberOfBlocks, -1, -1):
        if(j > i):
            print(" ", end="")
        else:
            print("#", end="")
    print(" ", end="")
    for j in range(numberOfBlocks):
        if(j > i):
            print(" ", end="")
        else:
            print("#", end="")
    print(" ")