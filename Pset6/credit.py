def desmember_number(number):
    mod = 0
    while number > 0:
        mod += number % 10
        number //= 10
    return mod

def type_of_card(size_of_number, card_number):
    card_identifier = 0
    for i in range(1, size_of_number + 1):
        if i == size_of_number - 1:
            card_identifier = card_number % 10
            card_number //= 10
        elif i == size_of_number:
            card_identifier += (card_number % 10) * 10
            card_number //= 10
        else:
            card_number //= 10
    return card_identifier

def main():
    credit_card = int(input("Digite o numero do cartão: "))
    credit_card_copy = credit_card

    count = 0
    mod_sum = 0
    product_sum = 0
    card_identifier = 0

    while credit_card > 0:
        if count == 1:
            mod = (credit_card % 10) * 2
            credit_card //= 10
            mod_sum += desmember_number(mod)
            count = 0
        else:
            product_sum += credit_card % 10
            credit_card //= 10
            count += 1

    product_sum += mod_sum
    card_identifier = type_of_card(len(str(credit_card_copy)), credit_card_copy)

    if product_sum % 10 == 0:
        if card_identifier == 34 or card_identifier == 37:
            print("AMEX")
        elif 50 < card_identifier <= 55:
            print("MasterCard")
        else:
            print("Visa")
    else:
        print("INVALID")

main()