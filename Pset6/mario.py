from cs50 import get_int
numberOfBlocks = get_int("Digite quantos blocos terá na pirâmide: ")

for i in range(numberOfBlocks):
    for j in range(numberOfBlocks, -1, -1):
        if(j > i):
            print(" ", end="")
        else:
            print("#", end="")

    print("")