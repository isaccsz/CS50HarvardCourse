def break_letters(text):
    counter_of_letters = 0
    count_of_words = 0
    count_of_sentences = 0

    for char in text:
        if char.isalpha():
            counter_of_letters += 1
            if char == '.' or char == '!' or char == '?':
                count_of_sentences += 1
            if char == ' ':
                count_of_words += 1
        elif char in ['.', '!', '?']:
            count_of_sentences += 1
            count_of_words += 1

    if count_of_words == 0:
        return 0.0

    index = 0.0588 * (counter_of_letters / count_of_words * 100) - 0.296 * (count_of_sentences / count_of_words * 100) - 15.8

    return index

def main():
    text = input("Digite o texto: ")
    result = break_letters(text)
    grade = round(result)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

main()