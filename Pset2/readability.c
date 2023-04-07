#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

float breakLetters(string text);

int main(void)
{

    string text = get_string("Digite o texto: ");
    float result;
    int grade;

    result = breakLetters(text);

    grade = round(result);

    if(grade < 1)
    {

        printf("Before Grade 1\n");

    }
    else if(grade > 16)
    {

        printf("Grade 16+\n");

    }
    else
    {

        printf("Grade %i\n",grade);

    }

}

float breakLetters(string text)
{

    int counterOfLetters = 0, countOfWords = 0, countOfSentences = 0;
    float index;

    for(int i = 0, n = strlen(text); i < n; i++)
    {

        if(text[i] != ' ' && text[i] != '.' && text[i] != ',' && text[i] != '?' && text[i] != '!' && text[i] != 39){

            counterOfLetters += 1;

            if(i == n-1){
                countOfSentences += 1;
                countOfWords += 1;
            }


        }
        else
        {

            if(text[i] == '.' || text[i] == '!' || text[i] == '?'){

                countOfSentences += 1;
                countOfWords += 1;

            }
            else if(text[i-1] != '.' && text[i-1] != '!' && text[i-1] != '?' && text[i-1] != ',' && text[i] != 39)
            {

                countOfWords += 1;

            }

        }

    }

    index = 0.0588 * ((counterOfLetters / (float) countOfWords)*100) - 0.296 * ((countOfSentences / (float) countOfWords)*100) - 15.8;

    return index;

}