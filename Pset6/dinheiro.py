import cs50

dinheiro = -1
while dinheiro < 0:
    dinheiro = cs50.get_float("Digite o valor: ")

cents = int(dinheiro * 100)  # Convertendo para centavos
actionsCount = 0

while cents != 0:
    if cents - 25 >= 0:
        cents -= 25
        actionsCount += 1
    elif cents - 10 >= 0:
        cents -= 10
        actionsCount += 1
    elif cents - 5 >= 0:
        cents -= 5
        actionsCount += 1
    elif cents - 1 >= 0:
        cents -= 1
        actionsCount += 1

print(actionsCount)