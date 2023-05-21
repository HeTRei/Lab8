#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
////////////////////////////////////////////////////////////////
void CheckIf_EqualNumOfBrackets(const std::string& Input)
{
    int NumOfOpenNormalBrackets = 0;
    int NumOfClosedNormalBrackets = 0;
    int NumOfOpenSquareBrackets = 0;
    int NumOfClosedSquareBrackets = 0;
    for (char i : Input)
        switch (i)
        {
            case '(':
                NumOfOpenNormalBrackets++;
                break;
            case ')':
                NumOfClosedNormalBrackets++;
                break;
            case '[':
                NumOfOpenSquareBrackets++;
                break;
            case ']':
                NumOfClosedSquareBrackets++;
            default:
                break;
        }
    if (NumOfOpenNormalBrackets == NumOfClosedNormalBrackets)
        std::cout << "Amount of open and closed normal brackets is equal, ";
    else
        std::cout << "Amount of open and closed normal brackets is not equal, ";
    if (NumOfOpenSquareBrackets == NumOfClosedSquareBrackets)
        std::cout << "amount of open and closed square brackets is equal." << std::endl;
    else
        std::cout << "amount of open and closed square brackets is not equal." << std::endl;
}
////////////////////////////////////////////////////////////////
void OutputLongestWord(const std::string& Input)
{
    std::string LongestWord;
    for (int i = 0; i < Input.size(); i++)
    {
        std::string CurrentWord;
        while (Input[i] != ' ' && Input[i] != '\0')
        {
            CurrentWord += Input[i];
            i++;
        }
        if (CurrentWord.size() > LongestWord.size())
            LongestWord = CurrentWord;
    }
    std::cout << LongestWord << std::endl;
}
////////////////////////////////////////////////////////////////
bool ContainsOnlyLatinLetters(const std::string& Word)
{
    for (char ch : Word)
    {
        if (!((65 <= ch && ch <= 90) || (97 <= ch && ch <= 122)))
            return false;
    }
    return true;
}
////////////////////////////////////////////////////////////////
std::string DeleteLatinWords(const std::string& Input)
{
    std::vector<std::string> Words;
    std::string Word;

    for (char ch : Input)
    {
        if (ch == ' ')
        {
            if (!Word.empty())
            {
                Words.push_back(Word);
                Word.clear();
            }
        }
        else
        {
            Word += ch;
        }
    }

    if (!Word.empty())
    {
        Words.push_back(Word);
    }

    std::string result;
    for (const std::string& w : Words)
    {
        if (!ContainsOnlyLatinLetters(w))
        {
            result += w + " ";
        }
    }

    if (!result.empty())
    {
        result.pop_back();
    }

    return result;
}
////////////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string Input;
    std::getline(std::cin, Input);
    CheckIf_EqualNumOfBrackets(Input);
    OutputLongestWord(Input);
    std::cout << DeleteLatinWords(Input);
    return 0;
}